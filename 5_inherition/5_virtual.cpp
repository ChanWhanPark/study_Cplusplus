#include <iostream>
#include <string>

class Base {
    std::string s;
public:
    Base() {std::cout << "based class" << std::endl;}
    virtual void what() {std::cout << "base class what()" << std::endl;}
};

class Derived : public Base {
public:
    Derived() :  Base() {
        std::cout << "derived class" << std::endl;
    }
    void what() {std::cout << "derived class what()" << std::endl;}
};

int main(){
    Base p;
    Derived c;

    Base* p_c = &c; // Derived의 주소를 가졌지만 Base의 구조체를 가리킴
    Base* p_p = &p;

    std::cout << "== Base == " << std::endl;
    p_p->what();

    std::cout << "== Derive ==" << std::endl;
    p_c->what();

    return 0;
}