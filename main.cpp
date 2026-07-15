#include "lesson01_basics.h"
#include "lesson02_class.h"
#include "lesson03_polymorphism.h"
#include "lesson04_template.h"
#include "lesson05_smartptr.h"
#include "lesson06_exception.h"
#include "lesson07_lambda.h"
#include "lesson08_move.h"
#include "lesson09_fileio.h"

// ============================================================
// main.cpp —— 程序总入口
//
// 每个知识点都拆分到独立的 lesson 文件中：
//   lesson01_basics      : 变量、控制流、函数、数组、指针、结构体
//   lesson02_class       : 类与对象、STL map、字符串操作
//   lesson03_polymorphism: 继承与多态、虚函数
//   lesson04_template    : 函数模板、类模板
//   lesson05_smartptr    : 智能指针（unique_ptr、shared_ptr、weak_ptr）
//   lesson06_exception   : 异常处理（try/catch/throw）
//   lesson07_lambda      : Lambda 表达式
//   lesson08_move        : 移动语义（std::move、右值引用）
//   lesson09_fileio      : 文件 I/O（ifstream/ofstream）
// ============================================================

int main() {

    // Lesson 01：基础语法
    demo_basics();

    // Lesson 02：类与对象 / STL map / 字符串
    demo_class();
    demo_stl_map();
    demo_string();

    // Lesson 03：继承与多态
    runPolymorphismDemo();

    // Lesson 04：模板
    runTemplateDemo();

    // Lesson 05：智能指针
    runSmartPtrDemo();

    // Lesson 06：异常处理
    runExceptionDemo();

    // Lesson 07：Lambda 表达式
    runLambdaDemo();

    // Lesson 08：移动语义
    runMoveDemo();

    // Lesson 09：文件 I/O
    runFileIODemo();

    return 0;
}
