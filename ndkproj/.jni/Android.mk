LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := key #so库引用名称  编译时会自动添加lib前缀，最后的结果为libkey.so
LOCAL_SRC_FILES := Help.cpp # 需要编译的源码

include $(BUILD_SHARED_LIBRARY)
