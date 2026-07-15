#include "lesson09_fileio.h"

static const std::string TEST_FILE   = "/tmp/cpp_lesson_test.txt";
static const std::string APPEND_FILE = "/tmp/cpp_lesson_append.txt";

void demoWriteFile() {
    std::cout << "\n--- 写入文本文件（ofstream）---" << std::endl;
    std::ofstream outFile(TEST_FILE);
    if (!outFile.is_open()) { std::cerr << "  无法打开文件: " << TEST_FILE << std::endl; return; }
    outFile << "第一行：Hello, C++ 文件 I/O！" << std::endl;
    outFile << "第二行：学习 ifstream 和 ofstream" << std::endl;
    outFile << "第三行：数字 " << 42 << "，浮点数 " << 3.14 << std::endl;
    outFile << "第四行：这是最后一行" << std::endl;
    outFile.close();
    std::cout << "  写入文件: " << TEST_FILE << std::endl;
}

void demoReadFile() {
    std::cout << "\n--- 读取文本文件（ifstream）---" << std::endl;
    std::ifstream inFile(TEST_FILE);
    if (!inFile.is_open()) { std::cerr << "  无法打开文件" << std::endl; return; }
    std::string line;
    int lineNum = 1;
    while (std::getline(inFile, line)) {
        std::cout << "  [行" << lineNum++ << "] " << line << std::endl;
    }
    inFile.close();
    std::cout << "  读取完毕，共 " << lineNum - 1 << " 行" << std::endl;
}

void demoReadLines() {
    std::cout << "\n--- 按行读取并统计 ---" << std::endl;
    std::ifstream inFile(TEST_FILE);
    if (!inFile.is_open()) { std::cerr << "  无法打开文件" << std::endl; return; }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line)) lines.push_back(line);
    inFile.close();
    int totalChars = 0;
    for (const auto& l : lines) totalChars += l.size();
    std::cout << "  总行数: " << lines.size() << std::endl;
    std::cout << "  总字符数: " << totalChars << std::endl;
    std::cout << "  最后一行: \"" << lines.back() << "\"" << std::endl;
}

void demoAppendFile() {
    std::cout << "\n--- 追加写入文件（ios::app）---" << std::endl;
    { std::ofstream f(APPEND_FILE); f << "初始内容：第一次写入" << std::endl; }
    for (int i = 1; i <= 3; ++i) {
        std::ofstream f(APPEND_FILE, std::ios::app);
        if (f.is_open()) f << "追加第 " << i << " 次" << std::endl;
    }
    std::cout << "  最终文件内容：" << std::endl;
    std::ifstream inFile(APPEND_FILE);
    std::string line;
    while (std::getline(inFile, line)) std::cout << "    " << line << std::endl;
}

void demoStringStream() {
    std::cout << "\n--- stringstream（字符串流）---" << std::endl;
    std::ostringstream oss;
    oss << "姓名: " << "张三" << "，年龄: " << 25 << "，分数: " << 98.5;
    std::cout << "  格式化结果: " << oss.str() << std::endl;
    std::string numStr = "3.14159";
    std::istringstream iss(numStr);
    double pi; iss >> pi;
    std::cout << "  字符串转 double = " << pi << std::endl;
    std::string sentence = "apple banana cherry date";
    std::istringstream tokenStream(sentence);
    std::string token;
    std::cout << "  分割结果: ";
    while (tokenStream >> token) std::cout << token << " ";
    std::cout << std::endl;
    std::string csv = "张三,25,北京,程序员";
    std::istringstream csvStream(csv);
    std::string field;
    std::cout << "  CSV 解析: ";
    while (std::getline(csvStream, field, ',')) std::cout << "[" << field << "] ";
    std::cout << std::endl;
}

void runFileIODemo() {
    std::cout << "===== 十六、文件 I/O（File Input/Output）=====" << std::endl;
    demoWriteFile();
    demoReadFile();
    demoReadLines();
    demoAppendFile();
    demoStringStream();
}
