#include <iostream>
#include <string>

class Base {
    std::string s;
public:
    Base() : s("base") {std::cout << "based class" << std::endl;}
    void what() {std::cout << s << std::endl;}
};

class Derived : public Base {
    std::string s;
public:
    Derived() : Base(), s("derived") {
        std::cout << "derived class" << std::endl;
        what();
    }

    void what() {std::cout << s << std::endl;}
};

int main(){
    std::cout << "===Based Class===" << std::endl;
    Base p;

    std::cout << "===Derived Class===" << std::endl;
    Derived c;
    // Base() 실행 -> Derived() 실행 -> Base() 기반 what() 실행 (Derived에 what()이 정의되지 않았을 시)
    // Base() 실행 -> Derived() 실행 -> Derived() 기반 what() 실행 (Derived에 what()이 정의되었을 시, Overriding)
    return 0;
}