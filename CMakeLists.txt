cmake_minimum_required(VERSION 3.26)
project(CPP_Test_01)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPP_Test_01
        main.cpp
        lesson01_basics.cpp
        lesson02_class.cpp
        lesson03_polymorphism.cpp
        lesson05_smartptr.cpp
        lesson06_exception.cpp
        lesson07_lambda.cpp
        lesson08_move.cpp
        lesson09_fileio.cpp
        # lesson04_template.h 是纯头文件（模板必须在头文件中），无需加入此处
)
