#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>

// ============================================================
// lesson08_move.h
// 主题：移动语义（Move Semantics）
// ============================================================

class MyBuffer {
public:
    explicit MyBuffer(int size);
    MyBuffer(const MyBuffer& other);
    MyBuffer(MyBuffer&& other) noexcept;
    MyBuffer& operator=(const MyBuffer& other);
    MyBuffer& operator=(MyBuffer&& other) noexcept;
    ~MyBuffer();

    int getSize() const { return size_; }
    int* getData() const { return data_; }
    void print(const std::string& label) const;

private:
    int* data_;
    int  size_;
};

void demoLvalueRvalue();
void demoCopyVsMove();
void demoStdMove();
void demoMoveInVector();
void runMoveDemo();
