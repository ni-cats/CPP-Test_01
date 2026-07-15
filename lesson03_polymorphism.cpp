
#include "lesson03_polymorphism.h"
#include <iostream>

Animal::Animal(const std::string& n) : name(n) {
    std::cout << "[Animal] " << name << " 被创建" << std::endl;
}

Animal::~Animal() {
    std::cout << "[Animal] " << name << " 被销毁" << std::endl;
}

void Animal::move() const {
    std::cout << name << " 在移动..." << std::endl;
}

std::string Animal::getName() const {
    return name;
}

Dog::Dog(const std::string& n, const std::string& b)
    : Animal(n), breed(b) {
    std::cout << "[Dog] " << name << "(" << breed << ") 被创建" << std::endl;
}

Dog::~Dog() {
    std::cout << "[Dog] " << name << " 被销毁" << std::endl;
}

void Dog::speak() const {
    std::cout << name << "(" << breed << ") 说：汪汪汪！" << std::endl;
}

void Dog::move() const {
    std::cout << name << " 欢快地奔跑！" << std::endl;
}

Cat::Cat(const std::string& n) : Animal(n) {
    std::cout << "[Cat] " << name << " 被创建" << std::endl;
}

Cat::~Cat() {
    std::cout << "[Cat] " << name << " 被销毁" << std::endl;
}

void Cat::speak() const {
    std::cout << name << " 说：喵喵喵～" << std::endl;
}

Bird::Bird(const std::string& n) : Animal(n) {
    std::cout << "[Bird] " << name << " 被创建" << std::endl;
}

Bird::~Bird() {
    std::cout << "[Bird] " << name << " 被销毁" << std::endl;
}

void Bird::speak() const {
    std::cout << name << " 说：叽叽喳喳！" << std::endl;
}

void Bird::move() const {
    std::cout << name << " 展翅飞翔！" << std::endl;
}

void runPolymorphismDemo() {
    std::cout << "===== 三、继承 与 多态（虚函数）=====" << std::endl;

    Animal* animals[3];
    animals[0] = new Dog("旺财", "柴犬");
    animals[1] = new Cat("咪咪");
    animals[2] = new Bird("小黄");

    std::cout << "\n--- 多态调用 speak() ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        animals[i]->speak();
    }

    std::cout << "\n--- 多态调用 move() ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        animals[i]->move();
    }

    std::cout << "\n--- 释放内存（注意析构顺序）---" << std::endl;
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
}
