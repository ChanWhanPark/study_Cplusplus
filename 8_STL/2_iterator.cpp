#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> &vec){
    // 전체 벡터 출력하기
    for (typename std::vector<int>::iterator itr = vec.begin(); itr!=vec.end();++itr){ // 의존 타입이므로 typename 추가
        std::cout << *itr << std::endl;
    }
}
int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    std::cout << "first vector" << std::endl;
    print_vector(vec);
    std::cout << "=======================" << std::endl;

    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout << "third element : " << *itr << std::endl;
    // 반복자를 포인터처럼 사용

    std::cout << "=======================" << std::endl;
    vec.erase(vec.begin() + 3);
    print_vector(vec);
}