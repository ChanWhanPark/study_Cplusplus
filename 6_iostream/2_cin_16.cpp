#include <iostream>
#include <string>

int main()
{
    int t;
    while (true){
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        std::cin >> t;
        std::cout << "Input : " << t << std::endl;
        if (std::cin.fail()){ // failbit인지 확인
            std::cout << "Wrong Input" << std::endl;
            std::cin.clear();
        }
        if (t == 0) break;
    }
}