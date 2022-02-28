#include <iostream>

int& function(int& a){ // a는 main의 b를 계속 참조
    a = 5;
    return a;
}

int main()
{
    int b = 2;
    int c = function(b);
    std::cout << b << c << std::endl;
}

// 참조자 리턴의 장점 : 구조체를 가리키는 포인터만을 리턴해 포인터 주소 한번 복사를 통해 시스템을 간단하게 만듦