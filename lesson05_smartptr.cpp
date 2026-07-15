
#include "lesson05_smartptr.h"

void demoUniquePtr() {
    std::cout << "\n--- unique_ptr（独占指针）---" << std::endl;

    {
        std::unique_ptr<Dog> uDog = std::make_unique<Dog>("旺财", "哈士奇");
        uDog->speak();
        uDog->move();
        std::cout << "  unique_ptr 持有: " << uDog->getName() << std::endl;

        std::unique_ptr<Dog> uDog2 = std::move(uDog);
        std::cout << "  所有权转移后，uDog2 持有: " << uDog2->getName() << std::endl;

        if (uDog == nullptr) {
            std::cout << "  uDog 已变为 nullptr（所有权已转移）" << std::endl;
        }
        std::cout << "  即将离开作用域..." << std::endl;
    }
    std::cout << "  已离开作用域，Dog 对象已自动销毁" << std::endl;

    std::cout << "\n  unique_ptr 指向基类（多态）:" << std::endl;
    std::unique_ptr<Animal> uAnimal = std::make_unique<Cat>("咪咪");
    uAnimal->speak();
}

void demoSharedPtr() {
    std::cout << "\n--- shared_ptr（共享指针）---" << std::endl;

    {
        std::shared_ptr<Cat> sCat = std::make_shared<Cat>("共享猫");
        std::cout << "  创建 sCat，引用计数: " << sCat.use_count() << std::endl;

        {
            std::shared_ptr<Cat> sCat2 = sCat;
            std::cout << "  复制为 sCat2，引用计数: " << sCat.use_count() << std::endl;
            sCat2->speak();

            std::shared_ptr<Cat> sCat3 = sCat;
            std::cout << "  复制为 sCat3，引用计数: " << sCat.use_count() << std::endl;
            std::cout << "  即将离开内层作用域..." << std::endl;
        }
        std::cout << "  离开内层作用域，引用计数: " << sCat.use_count() << std::endl;
        std::cout << "  即将离开外层作用域..." << std::endl;
    }
    std::cout << "  已离开外层作用域，Cat 对象已自动销毁" << std::endl;

    std::cout << "\n--- weak_ptr（弱引用指针）---" << std::endl;
    {
        std::shared_ptr<Bird> sBird = std::make_shared<Bird>("小黄");
        std::cout << "  sBird 引用计数: " << sBird.use_count() << std::endl;

        std::weak_ptr<Bird> wBird = sBird;
        std::cout << "  创建 wBird 后，sBird 引用计数: " << sBird.use_count() << std::endl;

        if (auto locked = wBird.lock()) {
            std::cout << "  lock() 成功，引用计数: " << sBird.use_count() << std::endl;
            locked->speak();
        }
        std::cout << "  lock() 离开作用域，引用计数: " << sBird.use_count() << std::endl;
    }
    std::cout << "  sBird 已销毁" << std::endl;
}

void demoSmartPtrWithPolymorphism() {
    std::cout << "\n--- 智能指针 + 多态 ---" << std::endl;
    {
        std::vector<std::shared_ptr<Animal>> zoo;
        zoo.push_back(std::make_shared<Dog>("智能狗", "金毛"));
        zoo.push_back(std::make_shared<Cat>("智能猫"));
        zoo.push_back(std::make_shared<Bird>("智能鸟"));

        std::cout << "  动物园里的动物们：" << std::endl;
        for (const auto& animal : zoo) {
            animal->speak();
            animal->move();
        }
        std::cout << "  即将离开作用域，所有动物自动销毁..." << std::endl;
    }
    std::cout << "  所有动物已销毁" << std::endl;
}

void runSmartPtrDemo() {
    std::cout << "===== 十二、智能指针（Smart Pointer）=====" << std::endl;
    demoUniquePtr();
    demoSharedPtr();
    demoSmartPtrWithPolymorphism();
}
