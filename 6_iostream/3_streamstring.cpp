#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    // 위치 지정자를 한 칸 옮기고, 그 다음 문자를 확인한다.
    char peek = std::cin.rdbuf()->snextc();
    if (std::cin.fail()) std::cout << "Failed";
    std::cout << "Second Word First Word : " << peek << std::endl;
    std::cin >> s;
    std::cout << "Repeat: " << s << std::endl;
}