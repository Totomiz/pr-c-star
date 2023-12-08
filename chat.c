//
// Created by Lenovot on 2023/12/1.
//


#include <jni.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netinet/in.h>

#include <unistd.h>
#include "com_chat_JChat.h"
#include <android/log.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>


#define TAG "ChatBox"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型

/*
 * Class:     com_chat_JChat
 * Method:    nativeSendMessage
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_com_chat_JChat_nativeSendMessage___3B
        (JNIEnv *env, jobject thiz, jbyteArray byteArray) {
    jint port = 8080;
    return Java_com_chat_JChat_nativeSendMessage___3BI(env, thiz, byteArray, port);
}

JNIEXPORT jboolean JNICALL Java_com_chat_JChat_nativeSendMessage___3BI
        (JNIEnv *env, jobject thiz, jbyteArray byteArray, jint port) {

    const char *ip = "127.0.0.1"; // 默认本地主机
    jstring ipv4 = (*env)->NewStringUTF(env, ip);
    jboolean result = Java_com_chat_JChat_nativeSendMessage___3BLjava_lang_String_2I(env, thiz,
                                                                                     byteArray,
                                                                                     ipv4, port);
    // 释放创建的jstring资源
    (*env)->DeleteLocalRef(env, ipv4);
    return result;
}

JNIEXPORT jboolean JNICALL Java_com_chat_JChat_nativeSendMessage___3BLjava_lang_String_2I
        (JNIEnv *env, jobject thiz, jbyteArray byteArray, jstring ipv4, jint port) {

    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == -1) {
        LOGD("create serverFd failed!");
        return JNI_FALSE;
    }
    const char *host = (*env)->GetStringUTFChars(env, ipv4, NULL);
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);

    if (connect(serverFd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        LOGD("conn serverFd failed!");
        (*env)->ReleaseStringChars(env, ipv4, host);
        close(serverFd);
    }
    (*env)->ReleaseStringChars(env, ipv4, host);

    jbyte *bytes = (*env)->GetByteArrayElements(env, byteArray, NULL);
    jsize len = (*env)->GetArrayLength(env, byteArray);
    ssize_t ret = send(serverFd, bytes, len, 0);
    (*env)->ReleaseByteArrayElements(env, byteArray, bytes, 0);
    // 关闭socket
    close(serverFd);

    // 判断是否发送成功
    if (ret == -1) {
        return JNI_FALSE;
    } else {
        return JNI_TRUE;
    }
}

/*
 * Class:     com_chat_JChat
 * Method:    nativeStartTcpServer
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_chat_JChat_nativeStartTcpServer
        (JNIEnv *env, jobject thiz, jint port) {
    errno = 0;
    // 创建socket
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == -1) {
        perror("ChatBox Faid:");
        fprintf(stderr, "%s Faid: %s\n", TAG, strerror(errno));
        LOGD("create StartTcpServer serverFd failed!");
        return;
    }

    // 绑定监听地址
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    // 设置端口号为0以请求系统分配随机端口
    //    addr.sin_port = htons(0);

    // 绑定socket
    if (bind(serverFd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind failed");
        close(serverFd);
        return;
    }

    int listenPort = 0;
    // 开始监听
    if ((listenPort = listen(serverFd, 10)) == -1) {
        close(serverFd);
        LOGD("listen StartTcpServer serverFd failed!");
        return;
    }

    // 获取系统分配的端口号
    struct sockaddr_in localAddr;
    socklen_t localAddrLen = sizeof(localAddr);
    if (getsockname(serverFd, (struct sockaddr *) &localAddr, &localAddrLen) == -1) {
        perror("getsockname failed");
        close(serverFd);
        return;
    }

    // 打印本地IP地址和端口号
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(localAddr.sin_addr), ip, INET_ADDRSTRLEN);
    int assignedPort = ntohs(localAddr.sin_port); // 获取系统分配的端口号
    LOGD("Local IP address: %s, Assigned Port: %d\n", ip, assignedPort);

    if (assignedPort >= 0) {
        jclass jChatClass = (*env)->GetObjectClass(env, thiz);
        jmethodID notifyPortMethodId = (*env)->GetMethodID(env, jChatClass, "notifyBindPort",
                                                           "(I)V");
        (*env)->CallVoidMethod(env, thiz, notifyPortMethodId, assignedPort);
    }


    // 循环接收客户端连接
    while (1) {
        struct sockaddr_in clientAddr;
        memset(&clientAddr, 0, sizeof(clientAddr));
        socklen_t len = sizeof(clientAddr);
        int clientFd = accept(serverFd, (struct sockaddr *) &clientAddr, &len);
        if (clientFd == -1) {
            continue;
        }

        // 接收消息
        char buf[1024] = {0};
        ssize_t ret = recv(clientFd, buf, sizeof(buf), 0);

        // 关闭客户端socket
        close(clientFd);

        // 判断是否接收到消息
        if (ret == -1) {
            continue;
        }

        // 将接收到的消息传递给Java层的receiveMessage方法
        jbyteArray byteArray = (*env)->NewByteArray(env, ret);
        (*env)->SetByteArrayRegion(env, byteArray, 0, ret, (jbyte *) buf);
        jclass jChatClass = (*env)->GetObjectClass(env, thiz);
        jmethodID receiveMessageMethodId = (*env)->GetMethodID(env, jChatClass, "receiveMessage",
                                                               "([B)V");
        (*env)->CallVoidMethod(env, thiz, receiveMessageMethodId, byteArray);
        (*env)->DeleteLocalRef(env, byteArray);
    }

    // 关闭服务器socket
    close(serverFd);
}

