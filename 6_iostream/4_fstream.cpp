#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream in("text.txt");
    std::string s;

    if (in.is_open()){ // 파일이 열렸는지에 대한 여부
        in >> s;
        std::cout << "Input String : " << s << std::endl;
    } else {
        std::cout << "Can't Find!" << std::endl;
    }
    return 0;
}