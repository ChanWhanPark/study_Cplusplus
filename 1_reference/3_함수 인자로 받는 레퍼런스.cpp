#include <iostream>
using namespace std;

int change_val(int &p){ // 함수가 호출될 때 number 실행
    p = 3;
    return 0;
}

int main()
{
    int number = 5;
    cout << number << endl;
    change_val(number);
    cout << number << endl;
}