cmake_minimum_required(VERSION 3.14)

# 获取项目根目录路径
get_filename_component(project_root "${CMAKE_SOURCE_DIR}" ABSOLUTE)

# 获取当前 CMakeLists.txt 文件所在的目录路径
get_filename_component(current_dir "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

# 计算项目名称
string(REPLACE "${project_root}/" "" project_name ${current_dir})
string(REPLACE "/" "-" project_name ${project_name})

# 使用计算得到的项目名称来设置 project
project(${project_name})
message("load project : ${project_name}")

# 使用file(GLOB ...)获取指定目录下的所有C源文件
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)


set(CMAKE_C_STANDARD 99)

# 遍历每个源文件，创建对应的可执行文件对象
foreach (source ${SOURCES})
    # 获取源文件的文件名（不包含路径和扩展名）
    get_filename_component(executable_name ${source} NAME_WE)
    set(MyExecutable "${project_name}-${executable_name}")
    set(S_TO_E "source file: ${source}\n\t -> [add executable] = ${MyExecutable}")
    message(${S_TO_E})
    # 添加可执行文件对象
    add_executable(${MyExecutable} ${source})
endforeach ()


# 语法可参考https://cmake.org/cmake/help/latest/command/get_filename_component.html#get-filename-component
#    DIRECTORY = Directory without file name
#    NAME      = File name without directory
#    EXT       = File name longest extension (.b.c from d/a.b.c)
#    NAME_WE   = File name with neither the directory nor the longest extension
#    LAST_EXT  = File name last extension (.c from d/a.b.c)
#    NAME_WLE  = File name with neither the directory nor the last extension
#    PATH      = Legacy alias for DIRECTORY (use for CMake <= 2.8.11)