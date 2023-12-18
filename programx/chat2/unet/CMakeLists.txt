add_library(unet sock.h sock-impl.c)
target_link_directories(unet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})