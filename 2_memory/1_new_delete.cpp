#include <iostream>
using namespace std;

int main()
{
    int* p = new int; // int 크기의 공간을 할당하여 그 주소값을 p에 삽입
    *p = 10;

    cout << *p << endl;

    delete p; // 할당된 공간 해세

    return 0;
}