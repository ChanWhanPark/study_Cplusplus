// 레퍼런스의 배열은 금지됨
#include <iostream>

int main()
{
    int arr[3] = {1, 2, 3};
    int (&ref)[3] = arr; // arr이라는 배열의 레퍼런스를 ref로 설정

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}