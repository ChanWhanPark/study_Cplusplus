#include <iostream>

class Parent{
public:
    Parent() {std::cout << "Parent Constructor" << std::endl;}
    virtual ~Parent() {std::cout << "Parent Destructor" << std::endl;}
};

class Child : public Parent{
public:
    Child() : Parent() {std::cout << "Child Constructor" << std::endl;}
    ~Child() {std::cout << "Child Destructor" << std::endl;}
};

int main()
{
    std::cout << "=== Normal Child ===" << std::endl;
    {Child c;}
    std::cout << "=== Parent Pointer to Child ===" << std::endl;
    {
        Parent* p = new Child();
        delete p;
    }
}