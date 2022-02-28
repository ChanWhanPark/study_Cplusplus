#include <iostream>
#include <string>

class Base {
protected:
    std::string parent_string;
public:
    Base() : parent_string("base") {std::cout << "based class" << std::endl;}
    void what() {std::cout << parent_string << std::endl;}
};

class Derived : public Base {
    std::string child_string;
public:
    Derived() : Base(), child_string("derived") {
        std::cout << "derived class" << std::endl;
        
        parent_string = "changed";
    }

    void what() {std::cout << child_string << std::endl;}
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