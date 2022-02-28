#include <iostream>
using namespace std;
int change_val(int *p){
    *p = 3; // 포인터를 통해 number를 참조하여 값 변경

    return 0;
}

int main()
{
    int number = 5;
    cout << number << endl;
    change_val(&number); // 주소값 전달
    cout << number << endl;
}