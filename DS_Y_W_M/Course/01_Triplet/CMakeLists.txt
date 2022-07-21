# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/DS_Y_W_M/Commom)

# 生成可执行文件
add_executable(01_Triplet Triplet.c)

# 链接公共库
target_link_libraries(01_Triplet basic)
