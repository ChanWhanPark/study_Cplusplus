// error
#include <iostream>

int& function(){
    int a = 2;
    return a;
} // 레퍼런스를 참조할 때 지역변수 a가 사라짐

int main()
{
    int b = function();
    std::cout << b << std::endl;
    b = 3;

    return 0;
}

// 따라서 레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않는다.