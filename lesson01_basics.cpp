#include "lesson01_basics.h"
#include <iostream>
#include <vector>
#include <algorithm>

void Point::print() const {
    std::cout << "Point(" << x << ", " << y << ")" << std::endl;
}

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

void greet(const std::string &name, const std::string &greeting) {
    std::cout << greeting << ", " << name << "!" << std::endl;
}

void doubleValue(int &x) { x = x * 2; }

void demo_basics() {
    std::cout << "===== 一、变量与基本数据类型 =====" << std::endl;
    int age = 25;
    double pi = 3.14159;
    char grade = 'A';
    bool isPassed = true;
    std::string name = "小明";
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << std::endl;
    std::cout << "圆周率: " << pi << std::endl;
    std::cout << "等级: " << grade << std::endl;
    std::cout << "是否通过: " << (isPassed ? "是" : "否") << std::endl;
    auto score = 98.5;
    std::cout << "分数(auto): " << score << std::endl;

    std::cout << "\n===== 二、控制流 =====" << std::endl;
    if (score >= 90) std::cout << "成绩优秀！" << std::endl;
    else if (score >= 60) std::cout << "成绩及格" << std::endl;
    else std::cout << "成绩不及格" << std::endl;

    std::cout << "for 循环 1~5: ";
    for (int i = 1; i <= 5; i++) std::cout << i << " ";
    std::cout << std::endl;

    int count = 3;
    std::cout << "while 倒计时: ";
    while (count > 0) std::cout << count-- << " ";
    std::cout << "发射！" << std::endl;

    int day = 3;
    switch (day) {
        case 1: std::cout << "星期一" << std::endl; break;
        case 2: std::cout << "星期二" << std::endl; break;
        case 3: std::cout << "星期三" << std::endl; break;
        default: std::cout << "其他" << std::endl; break;
    }

    std::cout << "\n===== 三、函数 =====" << std::endl;
    std::cout << "add(3, 4)      = " << add(3, 4) << std::endl;
    std::cout << "add(1.5, 2.5)  = " << add(1.5, 2.5) << std::endl;
    greet("小红");
    greet("小李", "早上好");
    int val = 10;
    doubleValue(val);
    std::cout << "doubleValue 后 val = " << val << std::endl;

    std::cout << "\n===== 四、数组 与 vector =====" << std::endl;
    int arr[5] = {10, 20, 30, 40, 50};
    std::cout << "静态数组: ";
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::vector<int> nums = {5, 3, 8, 1, 9, 2};
    nums.push_back(7);
    std::cout << "vector 原始: ";
    for (int n: nums) std::cout << n << " ";
    std::cout << std::endl;
    std::sort(nums.begin(), nums.end());
    std::cout << "vector 排序后: ";
    for (int n: nums) std::cout << n << " ";
    std::cout << "\nvector 大小: " << nums.size() << std::endl;

    std::cout << "\n===== 五、指针 与 引用 =====" << std::endl;
    int x = 42;
    int *ptr = &x;
    int &ref = x;
    std::cout << "x 的值: " << x << std::endl;
    std::cout << "ptr 指向的地址: " << ptr << std::endl;
    std::cout << "*ptr 解引用: " << *ptr << std::endl;
    std::cout << "ref 引用的值: " << ref << std::endl;
    *ptr = 100;
    std::cout << "通过指针修改后，x = " << x << std::endl;
    int *nullPtr = nullptr;
    if (nullPtr == nullptr) std::cout << "nullPtr 是空指针" << std::endl;

    std::cout << "\n===== 六、结构体 =====" << std::endl;
    Point p1 = {3.0, 4.0};
    p1.print();
    std::cout << "x = " << p1.x << ", y = " << p1.y << std::endl;
}
