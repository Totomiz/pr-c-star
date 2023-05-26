cmake_minimum_required(VERSION 3.14)
project(C_Unix)
set(CMAKE_C_STANDARD 99)

add_executable(01_process_func process/01_process_func.c)
add_executable(01_basic_01_ls 01_basic/01_ls.c)
add_executable(01_basic_02_cp 01_basic/02_cp.c)

# 指定APUE库的头文件和库文件路径
include_directories(/usr/include)
link_directories(/usr/lib)

# 定义变量来保存需要链接的库的名称
set(LINK_LIBS apue bsd)
# 链接APUE库
target_link_libraries(01_basic_01_ls ${LINK_LIBS})
target_link_libraries(01_basic_02_cp ${LINK_LIBS})
target_link_libraries(01_process_func ${LINK_LIBS})