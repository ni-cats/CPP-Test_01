#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

// ============================================================
// lesson06_exception.h
// 主题：异常处理（try/catch/throw）
// ============================================================

class DivideByZeroException : public std::runtime_error {
public:
    explicit DivideByZeroException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class NegativeAgeException : public std::logic_error {
public:
    explicit NegativeAgeException(int age)
        : std::logic_error("年龄不能为负数，传入值: " + std::to_string(age)) {}
};

void demoBasicException();
void demoMultiCatch();
void demoCustomException();
void demoExceptionPropagation();
void runExceptionDemo();
