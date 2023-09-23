cmake_minimum_required(VERSION 3.14)

get_filename_component(project_dir_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# message("current Name: ${project_dir_name}")
# message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

project(${project_dir_name})

set(CMAKE_C_STANDARD 99)

# 定义要排除的目录列表
set(exclude_dirs "makegrammar" "dir2" "dir3")

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

