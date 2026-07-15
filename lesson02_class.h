
#pragma once
#include <iostream>
#include <string>
#include <map>

// ============================================================
// lesson02_class.h
// 内容：类与对象、STL map、字符串操作
// ============================================================

// ---- 类（Class）：封装、构造函数、成员函数 ----
class Rectangle {
private:
    double width;    // 私有成员，外部不能直接访问
    double height;

public:
    // 构造函数：用初始化列表赋值（推荐写法）
    Rectangle(double w, double h);

    // 析构函数（对象销毁时自动调用）
    ~Rectangle();

    // 成员函数（const 表示不修改成员变量）
    double area() const;
    double perimeter() const;

    // Getter：访问私有成员
    double getWidth()  const { return width; }
    double getHeight() const { return height; }
};

// ---- 演示函数声明 ----
void demo_class();      // 演示类与对象
void demo_stl_map();    // 演示 STL map
void demo_string();     // 演示字符串操作
