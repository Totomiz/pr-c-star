

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

set(CMAKE_C_STANDARD 99)


# 定义要排除的目录列表
set(exclude_dirs "dir1" "dir2" "student1")

# 添加当前目录下的所有非cmake-开头的子目录 .开头的目录
file(GLOB subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
foreach (subdir ${subdirs})
    if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} AND
            NOT ${subdir} MATCHES "^cmake" AND
            NOT ${subdir} MATCHES "^\\." AND
            NOT "${subdir}" IN_LIST exclude_dirs
    )
        add_subdirectory(${subdir})
    endif ()
endforeach ()

