
#include "lesson02_class.h"
#include <iostream>
#include <string>
#include <map>

// ============================================================
// lesson02_class.cpp
// ============================================================

// ---- Rectangle 成员函数实现 ----

Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    std::cout << "[Rectangle] 创建了一个 " << w << " x " << h << " 的矩形" << std::endl;
}

Rectangle::~Rectangle() {
    std::cout << "[Rectangle] 矩形对象被销毁" << std::endl;
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

// ---- 演示函数实现 ----

void demo_class() {
    std::cout << "\n===== 七、类与对象 =====" << std::endl;

    Rectangle rect(5.0, 3.0);
    std::cout << "面积: "   << rect.area()      << std::endl;
    std::cout << "周长: "   << rect.perimeter() << std::endl;
    std::cout << "宽度: "   << rect.getWidth()  << std::endl;
    std::cout << "高度: "   << rect.getHeight() << std::endl;
}

void demo_stl_map() {
    std::cout << "\n===== 八、STL map（键值对容器）=====" << std::endl;

    std::map<std::string, int> scores;
    scores["小明"] = 95;
    scores["小红"] = 88;
    scores.insert({"小李", 72});

    std::cout << "所有成绩：" << std::endl;
    for (const auto& [key, val] : scores) {
        std::cout << "  " << key << " -> " << val << std::endl;
    }

    if (scores.count("小明")) {
        std::cout << "找到小明，分数为: " << scores["小明"] << std::endl;
    }

    scores["小明"] = 100;
    std::cout << "修改后小明的分数: " << scores["小明"] << std::endl;

    scores.erase("小李");
    std::cout << "删除小李后，map 大小: " << scores.size() << std::endl;
}

void demo_string() {
    std::cout << "\n===== 九、字符串操作 =====" << std::endl;

    std::string s1 = "Hello";
    std::string s2 = " World";
    std::string s3 = s1 + s2;
    std::cout << "拼接结果: "        << s3                        << std::endl;
    std::cout << "长度: "            << s3.size()                 << std::endl;
    std::cout << "子串(0,5): "       << s3.substr(0, 5)           << std::endl;
    std::cout << "查找'World'位置: " << s3.find("World")          << std::endl;
    std::cout << "是否为空: "        << (s3.empty() ? "是" : "否") << std::endl;

    s3.replace(s3.find("World"), 5, "C++");
    std::cout << "替换后: " << s3 << std::endl;

    std::string upper = s3;
    for (char& c : upper) {
        if (c >= 'a' && c <= 'z') c -= 32;
    }
    std::cout << "转大写: " << upper << std::endl;
}
