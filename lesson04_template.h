
#pragma once
#include <iostream>
#include <string>
#include <vector>

// ============================================================
// lesson04_template.h
// 主题：模板（Template）
// 注意：模板实现必须写在头文件中
// ============================================================

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
void printPair(const T1& first, const T2& second) {
    std::cout << "  (" << first << ", " << second << ")" << std::endl;
}

template <typename T>
void printVector(const std::string& label, const std::vector<T>& vec) {
    std::cout << "  " << label << ": [";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
        std::cout << "  入栈: " << value << std::endl;
    }

    void pop() {
        if (data.empty()) {
            std::cout << "  栈为空，无法出栈！" << std::endl;
            return;
        }
        std::cout << "  出栈: " << data.back() << std::endl;
        data.pop_back();
    }

    const T& top() const { return data.back(); }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

inline void runTemplateDemo() {
    std::cout << "===== 四、模板（Template）=====" << std::endl;

    std::cout << "\n--- 函数模板 maxValue ---" << std::endl;
    std::cout << "  maxValue(3, 7)          = " << maxValue(3, 7) << std::endl;
    std::cout << "  maxValue(3.14, 2.71)    = " << maxValue(3.14, 2.71) << std::endl;
    std::cout << "  maxValue(\"apple\",\"banana\") = "
              << maxValue(std::string("apple"), std::string("banana")) << std::endl;

    std::cout << "\n--- 函数模板 printPair ---" << std::endl;
    printPair("姓名", "小明");
    printPair("年龄", 25);
    printPair(3.14, true);

    std::cout << "\n--- 函数模板 printVector ---" << std::endl;
    std::vector<int>         vi = {1, 2, 3, 4, 5};
    std::vector<double>      vd = {1.1, 2.2, 3.3};
    std::vector<std::string> vs = {"C++", "Python", "Lua"};
    printVector("整数 vector", vi);
    printVector("浮点 vector", vd);
    printVector("字符串 vector", vs);

    std::cout << "\n--- 类模板 Stack<int> ---" << std::endl;
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    std::cout << "  栈顶元素: " << intStack.top() << std::endl;
    intStack.pop();
    intStack.pop();
    std::cout << "  剩余大小: " << intStack.size() << std::endl;

    std::cout << "\n--- 类模板 Stack<string> ---" << std::endl;
    Stack<std::string> strStack;
    strStack.push("第一层");
    strStack.push("第二层");
    strStack.push("第三层");
    strStack.pop();
    std::cout << "  当前栈顶: " << strStack.top() << std::endl;
}
