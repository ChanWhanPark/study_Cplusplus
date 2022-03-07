#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (std::vector<int>::size_type i = 0;i<vec.size();i++){
        std::cout << "vec's " << i + 1 << " elements : " << vec[i] << std::endl;
    }
}

// 벡터의 복잡도
// 임의의 위치 원소 접근 : O(1)
// 맨 뒤의 원소 추가 및 제거 : amortized O(1)
// 임의의 위치 원소 추가 및 제거 : O(n)