#include "lesson06_exception.h"

double safeDivide(double a, double b) {
    if (b == 0.0) {
        throw DivideByZeroException("safeDivide: 除数不能为零！");
    }
    return a / b;
}

void demoBasicException() {
    std::cout << "\n--- 基本 try/catch/throw ---" << std::endl;
    try {
        std::cout << "  尝试计算 10 / 2 = " << safeDivide(10, 2) << std::endl;
        std::cout << "  尝试计算 5 / 0 ..." << std::endl;
        safeDivide(5, 0);
        std::cout << "  这行不会被执行！" << std::endl;
    }
    catch (const DivideByZeroException& e) {
        std::cout << "  捕获到 DivideByZeroException: " << e.what() << std::endl;
    }
    std::cout << "  程序继续正常运行" << std::endl;
}

void demoMultiCatch() {
    std::cout << "\n--- 捕获多种异常类型 ---" << std::endl;
    auto testException = [](int testCase) {
        try {
            if (testCase == 1) throw std::out_of_range("下标越界：index = 100");
            else if (testCase == 2) throw std::runtime_error("运行时错误：网络连接失败");
            else if (testCase == 3) throw 42;
        }
        catch (const std::out_of_range& e)    { std::cout << "  [out_of_range] " << e.what() << std::endl; }
        catch (const std::runtime_error& e)   { std::cout << "  [runtime_error] " << e.what() << std::endl; }
        catch (const std::exception& e)       { std::cout << "  [std::exception] " << e.what() << std::endl; }
        catch (...)                            { std::cout << "  [未知异常]" << std::endl; }
    };
    testException(1); testException(2); testException(3);
}

void setAge(int age) {
    if (age < 0) throw NegativeAgeException(age);
    std::cout << "  年龄设置为: " << age << std::endl;
}

void demoCustomException() {
    std::cout << "\n--- 自定义异常类 ---" << std::endl;
    try {
        setAge(25);
        setAge(-5);
    }
    catch (const NegativeAgeException& e) {
        std::cout << "  捕获到自定义异常: " << e.what() << std::endl;
    }
}

void level3() {
    std::cout << "    [level3] 抛出异常..." << std::endl;
    throw std::runtime_error("来自 level3 的错误");
}
void level2() { std::cout << "   [level2] 调用 level3..." << std::endl; level3(); }
void level1() { std::cout << "  [level1] 调用 level2..." << std::endl; level2(); }

void demoExceptionPropagation() {
    std::cout << "\n--- 异常传播（冒泡）---" << std::endl;
    try { level1(); }
    catch (const std::runtime_error& e) {
        std::cout << "  在顶层捕获到异常: " << e.what() << std::endl;
    }
    std::cout << "  程序继续运行" << std::endl;
}

void runExceptionDemo() {
    std::cout << "===== 十三、异常处理（Exception Handling）=====" << std::endl;
    demoBasicException();
    demoMultiCatch();
    demoCustomException();
    demoExceptionPropagation();
}
