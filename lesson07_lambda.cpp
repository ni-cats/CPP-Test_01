#include "lesson07_lambda.h"

void demoLambdaBasic() {
    std::cout << "\n--- Lambda 基本语法 ---" << std::endl;

    auto sayHello = []() { std::cout << "  Hello from Lambda!" << std::endl; };
    sayHello();

    auto add = [](int a, int b) { return a + b; };
    std::cout << "  add(3, 4) = " << add(3, 4) << std::endl;

    auto divide = [](double a, double b) -> double {
        if (b == 0) return 0.0;
        return a / b;
    };
    std::cout << "  divide(10.0, 3.0) = " << divide(10.0, 3.0) << std::endl;

    int result = [](int x) { return x * x; }(7);
    std::cout << "  7 的平方 = " << result << std::endl;
}

void demoLambdaCapture() {
    std::cout << "\n--- 捕获列表 ---" << std::endl;

    int base = 100;
    std::string prefix = "值是";

    auto captureByValue = [=]() {
        std::cout << "  [按值捕获] " << prefix << ": " << base << std::endl;
    };
    captureByValue();
    std::cout << "  外部 base 仍然是: " << base << std::endl;

    auto captureByRef = [&]() {
        base += 50;
        std::cout << "  [按引用捕获] 修改后 base = " << base << std::endl;
    };
    captureByRef();
    std::cout << "  外部 base 现在是: " << base << std::endl;

    int x = 10, y = 20;
    auto mixed = [=, &x]() {
        x += 5;
        std::cout << "  [混合捕获] x=" << x << ", y=" << y << std::endl;
    };
    mixed();
    std::cout << "  混合捕获后 x=" << x << ", y=" << y << std::endl;

    int count = 0;
    auto counter = [count]() mutable {
        count++;
        std::cout << "  [mutable] 内部 count = " << count << std::endl;
    };
    counter(); counter();
    std::cout << "  外部 count 仍然是: " << count << std::endl;
}

void demoLambdaWithSTL() {
    std::cout << "\n--- Lambda 与 STL 算法 ---" << std::endl;

    std::vector<int> nums = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
    std::cout << "  升序排序: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    std::cout << "  降序排序: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "  每个元素乘以2: ";
    std::for_each(nums.begin(), nums.end(), [](int& n) { n *= 2; });
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    auto it = std::find_if(nums.begin(), nums.end(), [](int n) { return n > 10; });
    if (it != nums.end()) std::cout << "  第一个大于10的元素: " << *it << std::endl;

    int threshold = 10;
    int cnt = std::count_if(nums.begin(), nums.end(), [threshold](int n) { return n > threshold; });
    std::cout << "  大于 " << threshold << " 的元素个数: " << cnt << std::endl;
}

void demoStdFunction() {
    std::cout << "\n--- std::function 存储 Lambda ---" << std::endl;

    std::function<int(int, int)> op;
    op = [](int a, int b) { return a + b; };
    std::cout << "  加法: 3 + 4 = " << op(3, 4) << std::endl;
    op = [](int a, int b) { return a * b; };
    std::cout << "  乘法: 3 * 4 = " << op(3, 4) << std::endl;

    std::vector<std::function<int(int)>> transforms;
    transforms.push_back([](int x) { return x * 2; });
    transforms.push_back([](int x) { return x + 10; });
    transforms.push_back([](int x) { return x * x; });

    int val = 5;
    std::cout << "  对 " << val << " 依次应用变换: ";
    for (auto& f : transforms) { val = f(val); std::cout << val << " "; }
    std::cout << std::endl;
}

void runLambdaDemo() {
    std::cout << "===== 十四、Lambda 表达式 =====" << std::endl;
    demoLambdaBasic();
    demoLambdaCapture();
    demoLambdaWithSTL();
    demoStdFunction();
}
