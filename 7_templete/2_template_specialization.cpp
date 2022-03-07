#include <iostream>
#include <string>

template <typename T>
class Vector{
    T* data;
    int capacity;
    int length;

public:
    typedef T value_type; // 어떤 Type을 보관하는지

    Vector(int n=1) : data(new T[n]), capacity(n), length(0) {} // 생성자
    
    void push_back(T s){ // 맨 뒤에 새로운 원소 추가
        if (capacity <= length){
            T* temp = new T[capacity * 2];
            for (int i=0;i<length;i++) temp[i] = data[i];
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        data[length] = s;
        length++;
    }

    T operator[](int i) {return data[i];} // 임의의 위치의 원소에 접근한다.

    void remove(int x){ // x 번째 위치한 원소를 제거한다.
        for (int i=x+1;i<length;i++) data[i-1] = data[i];
        length--;
    }

    int size() {return length;} // 현재 벡터의 크기를 구한다.

    ~Vector() {if (data) delete[] data;}
};

// 템플릿 특수화
template <>
class Vector<bool>{ // bool형에 대해서만 특수화
    unsigned int* data;
    int capacity;
    int length;
public:
    typedef bool value_type;
    Vector(int n=1) : data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) {
        for (int i=0;i<capacity;i++) data[i] = 0;
    } // 생성자

    void push_back(bool s){ // 맨 뒤에 새로운 원소 추가
        if (capacity * 32 <= length){
            unsigned int* temp = new unsigned int[capacity * 2];
            for (int i=0;i<length;i++) temp[i] = data[i];
            for (int i=capacity;i<2*capacity;i++) temp[i] = 0;

            delete[] data;
            data = temp;
            capacity *= 2;
        }
        if (s){
            data[length / 32] |= (1 << (length % 32));
        }

        length++;
    }

    bool operator[] (int i) {return (data[i/32] & ( 1 << (i % 32))) != 0;}
    void remove(int x){ // x 번째 위치한 원소를 제거한다.
        for (int i=x+1;i<length;i++){
            int prev = i - 1;
            int curr = i;

            // curr 위치에 있는 비트가 1이라면 prev 위치에 있는 비트를 1로 만든다.
            if (data[curr / 32] & (1 << (curr % 32))){
                data[prev/32] |= (1 << (prev % 32));
            }
            else{
                unsigned int all_ones_except_prev = 0xFFFFFFFF;
                all_ones_except_prev ^= (1 << (prev % 32));
                data[prev / 32] &= all_ones_except_prev;
            }
        }
        length--;
    }
    int size() {return length;}
    ~Vector(){
        if (data) delete[] data;
    }
};

int main()
{
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "======= int vector =======" << std::endl;
    std::cout << "First : " << int_vec[0] << std::endl;
    std::cout << "Second : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");

    std::cout << "======= string vector =======" << std::endl;
    std::cout << "First : " << str_vec[0] << std::endl;
    std::cout << "Second : " << str_vec[1] << std::endl;

    Vector<bool> bool_vec;
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);

    std::cout << "======= bool vector =======" << std::endl;
    for (int i=0;i<bool_vec.size();i++){
        std::cout << bool_vec[i];
    }
    std::cout << std::endl;
}