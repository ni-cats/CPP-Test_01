
#pragma once
#include <iostream>
#include <string>

// ============================================================
// lesson03_polymorphism.h
// 主题：继承 与 多态（虚函数）
//
// 核心概念：
//   - 继承（Inheritance）：子类复用父类的属性和方法
//   - 多态（Polymorphism）：父类指针/引用调用虚函数时，
//     运行时自动执行子类的版本
//   - 虚函数（virtual）：开启运行时多态的关键字
//   - 纯虚函数（= 0）：子类必须实现，使类变为抽象类
//   - override：子类重写时加上，让编译器帮你检查
// ============================================================

class Animal {
protected:
    std::string name;

public:
    explicit Animal(const std::string& n);
    virtual ~Animal();
    virtual void speak() const = 0;
    virtual void move() const;
    std::string getName() const;
};

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& n, const std::string& b);
    ~Dog() override;
    void speak() const override;
    void move()  const override;
};

class Cat : public Animal {
public:
    explicit Cat(const std::string& n);
    ~Cat() override;
    void speak() const override;
};

class Bird : public Animal {
public:
    explicit Bird(const std::string& n);
    ~Bird() override;
    void speak() const override;
    void move()  const override;
};

void runPolymorphismDemo();
