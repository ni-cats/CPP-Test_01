#include "lesson08_move.h"

MyBuffer::MyBuffer(int size) : size_(size), data_(new int[size]) {
    for (int i = 0; i < size_; ++i) data_[i] = i;
    std::cout << "    [构造] MyBuffer(size=" << size_ << ") 分配内存 @" << data_ << std::endl;
}

MyBuffer::MyBuffer(const MyBuffer& other) : size_(other.size_), data_(new int[other.size_]) {
    for (int i = 0; i < size_; ++i) data_[i] = other.data_[i];
    std::cout << "    [拷贝构造] 深拷贝 size=" << size_
              << "，新地址 @" << data_ << "（原地址 @" << other.data_ << "）" << std::endl;
}

MyBuffer::MyBuffer(MyBuffer&& other) noexcept
    : size_(other.size_), data_(other.data_) {
    other.data_ = nullptr;
    other.size_ = 0;
    std::cout << "    [移动构造] 转移指针 @" << data_ << "（原对象已置空）" << std::endl;
}

MyBuffer& MyBuffer::operator=(const MyBuffer& other) {
    if (this == &other) return *this;
    delete[] data_;
    size_ = other.size_;
    data_ = new int[size_];
    for (int i = 0; i < size_; ++i) data_[i] = other.data_[i];
    std::cout << "    [拷贝赋值] 深拷贝 size=" << size_ << std::endl;
    return *this;
}

MyBuffer& MyBuffer::operator=(MyBuffer&& other) noexcept {
    if (this == &other) return *this;
    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;
    other.data_ = nullptr;
    other.size_ = 0;
    std::cout << "    [移动赋值] 转移指针 @" << data_ << std::endl;
    return *this;
}

MyBuffer::~MyBuffer() {
    if (data_) {
        std::cout << "    [析构] 释放内存 @" << data_ << " size=" << size_ << std::endl;
        delete[] data_;
    } else {
        std::cout << "    [析构] 空对象，无需释放" << std::endl;
    }
}

void MyBuffer::print(const std::string& label) const {
    std::cout << "    " << label << ": [";
    for (int i = 0; i < size_ && i < 5; ++i) {
        std::cout << data_[i];
        if (i < size_ - 1 && i < 4) std::cout << ", ";
    }
    if (size_ > 5) std::cout << "...";
    std::cout << "] size=" << size_ << std::endl;
}

void demoLvalueRvalue() {
    std::cout << "\n--- 左值 vs 右值 ---" << std::endl;
    int a = 10, b = 20;
    int& refA = a;
    refA = 99;
    std::cout << "  左值引用修改 a = " << a << std::endl;
    int&& rref = 42;
    int&& rref2 = a + b;
    std::cout << "  右值引用 rref = " << rref << std::endl;
    std::cout << "  右值引用 rref2 = " << rref2 << std::endl;
    int&& rref3 = std::move(a);
    std::cout << "  std::move(a) 得到右值引用 = " << rref3 << std::endl;
}

void demoCopyVsMove() {
    std::cout << "\n--- 拷贝构造 vs 移动构造 ---" << std::endl;
    std::cout << "  创建原始 buffer:" << std::endl;
    MyBuffer original(5);
    original.print("original");
    std::cout << "\n  执行拷贝构造（深拷贝）:" << std::endl;
    MyBuffer copied = original;
    copied.print("copied");
    original.print("original（拷贝后仍然完整）");
    std::cout << "\n  执行移动构造（转移所有权）:" << std::endl;
    MyBuffer moved = std::move(original);
    moved.print("moved");
    std::cout << "    original 被移动后 size=" << original.getSize()
              << "，data=" << original.getData() << std::endl;
}

void demoStdMove() {
    std::cout << "\n--- std::move 使用场景 ---" << std::endl;
    std::string s1 = "这是一个很长很长的字符串，拷贝代价很高";
    std::cout << "  移动前 s1 = \"" << s1 << "\"" << std::endl;
    std::string s2 = std::move(s1);
    std::cout << "  移动后 s2 = \"" << s2 << "\"" << std::endl;
    std::cout << "  移动后 s1 = \"" << s1 << "\"（已被清空）" << std::endl;
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << "\n  移动前 v1.size() = " << v1.size() << std::endl;
    std::vector<int> v2 = std::move(v1);
    std::cout << "  移动后 v2.size() = " << v2.size() << std::endl;
    std::cout << "  移动后 v1.size() = " << v1.size() << "（已被清空）" << std::endl;
}

void demoMoveInVector() {
    std::cout << "\n--- vector 中的移动语义 ---" << std::endl;
    std::vector<MyBuffer> buffers;
    buffers.reserve(3);
    std::cout << "  push_back 临时对象（右值）→ 触发移动构造:" << std::endl;
    buffers.push_back(MyBuffer(3));
    std::cout << "\n  push_back 左值 → 触发拷贝构造:" << std::endl;
    MyBuffer buf(4);
    buffers.push_back(buf);
    std::cout << "\n  push_back std::move(左值) → 触发移动构造:" << std::endl;
    MyBuffer buf2(5);
    buffers.push_back(std::move(buf2));
}

void runMoveDemo() {
    std::cout << "===== 十五、移动语义（Move Semantics）=====" << std::endl;
    demoLvalueRvalue();
    demoCopyVsMove();
    demoStdMove();
    demoMoveInVector();
}
