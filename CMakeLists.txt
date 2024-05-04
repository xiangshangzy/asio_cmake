cmake_minimum_required(VERSION 3.20) # cmake版本最低要求
project(asio)  # 设置工程名称

set(CMAKE_CXX_STANDARD 20)  # 指定 C++ 版本
set(CMAKE_BUILD_TYPE Release)  # 调试使用Debug，可以查看中间变量；发布使用Release，运行速度快


# 设置可执行文件的输出目录和库文件的输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)	   

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/main) 
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/static) 
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/third) 
