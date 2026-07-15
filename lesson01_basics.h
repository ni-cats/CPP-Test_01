
#pragma once
#include <string>

// ============================================================
// Lesson 01：基础语法
//   - 变量与数据类型
//   - 控制流（if/for/while/switch）
//   - 函数（重载、默认参数、引用传参）
//   - 数组 与 vector
//   - 指针 与 引用
//   - 结构体
// ============================================================

int    add(int a, int b);
double add(double a, double b);

void greet(const std::string& name, const std::string& greeting = "你好");
void doubleValue(int& x);

struct Point {
    double x;
    double y;
    void print() const;
};

void demo_basics();
