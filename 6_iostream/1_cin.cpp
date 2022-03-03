#include <iostream>
#include <string>

int main()
{
    int t;
    while (true) {
        std::cin >> t;
        std::cout << "Input : " << t << std::endl;
        if (std::cin.fail()){ // failbit인지 확인
            std::cout << "Wrong Input" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n'); // 개행문자가 나올 때까지 무시한다
        }
        if (t == 0) break;
    }
}