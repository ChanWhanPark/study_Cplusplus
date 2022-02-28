#include <iostream>
using namespace std;

int main()
{
    int a = 3;
    int& another_a = a; // 참조

    another_a = 5; // another_a에서의 작업은 a에 작업하는 것과 같음
    cout << "a : " << a << endl;
    cout << "another_a : " << another_a << endl;

    return 0;
}