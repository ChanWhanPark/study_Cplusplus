#include <iostream>
#include <string>

template <typename T>
class Vector{
    T* data;
    int capacity;
    int length;

public:
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

    void swap(int i, int j){
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    ~Vector() {if (data) delete[] data;}
};

template <typename Cont>
void bubble_sort(Cont& cont){
    for (int i=0;i<cont.size();i++){
        for (int j=i+1;j<cont.size();j++){
            if (cont[i] > cont[j]) cont.swap(i, j);
        }
    }
}

int main()
{
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(5);
    int_vec.push_back(0);
    int_vec.push_back(4);

    std::cout << "Sort Before ==== " << std::endl;
    for (int i=0;i<int_vec.size();i++) std::cout << int_vec[i] << " ";

    std::cout << std::endl << "Sort After ====" << std::endl;
    bubble_sort(int_vec);
    for (int i=0;i<int_vec.size();i++) std::cout << int_vec[i] << " ";
    std::cout << std::endl;

    
}