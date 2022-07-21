# usr/python3
import os
import re

if __name__ == "__main__":
    pwd = os.getcwd()
    projectRootPath = pwd
    print(f"当前工作目录 ${pwd}")
    for i in os.listdir(pwd):
        absPath=os.path.abspath(i)
        if os.path.isdir(absPath):
            print(f"pwd--->{i}---{os.path.abspath(i)}")

    filterDirs = ["build", "cmake-build-debug", "CmakeFiles"]
    loverFilter = []
    for i in filterDirs:
        loverFilter.append(i.lower())
    for root, dirs, files in os.walk(pwd):
        for dir in dirs:
            if loverFilter.__contains__(dir.lower()) or dir.__contains__('.') or dir.__contains__('$'):
                continue
            else:
                print(f"子目录 {dir}")
            # for file in files:
            #     print(f"子文件 ${file}")
