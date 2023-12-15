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

add_executable(cbo cbox.c)
add_executable(cbo2 cbox2.c)