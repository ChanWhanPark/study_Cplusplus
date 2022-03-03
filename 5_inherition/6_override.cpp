#include <iostream>
#include <string>

class Base {
    std::string s;
public:
    Base() : s("base") {std::cout << "based class" << std::endl;}

    virtual void incorrect() {std::cout << "based class" << std::endl;}
};

class Derived : public Base {
    std::string s;
public:
    Derived() : Base(), s("derived") {}

    void incorrect() override {std::cout << "derived class" << std::endl;}
};

int main(){
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    std::cout << "== Base ==" << std::endl;
    p_p->incorrect();

    std::cout << "== Derived ==" << std::endl;
    p_c->incorrect();
    return 0;
}