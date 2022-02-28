#include <iostream>

int function(){
    int a = 5;
    return a;
}

int main(){
    const int& c = function(); 
    // 상수 레퍼런스로 리턴값을 받으면 해당 리턴값은 레퍼런스가 사라질때까지 유효
    std::cout << "c : " << c << std::endl;
    return 0;
}

/*
메모리에 존재하지 않아도 되는 경우
: 레퍼런스가 함수 내 별칭으로만 쓰일 때,
: 컴파일러 내부 동작은 모르나 별칭을 replace하는 방식으로 구현

메모리에 존재해야 하는 경우
: 인자로 넘기는 경우
: 리턴값을 상수(const) 참조자로 받는 경우