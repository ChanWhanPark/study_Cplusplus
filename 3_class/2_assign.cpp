#include <iostream>
#include <string.h>

class MyString { 
    // 문자열 데이터를 가리키는 포인터와 문자열 길이를 private로 설정
private:    
    char* string_content;
    int string_length;
    int memory_capacity; // 현재 할당된 용량

public:
    MyString(char c); // 문자 하나로 생성
    MyString(const char* str); // 문자열로부터 생성
    MyString(const MyString& str); // 복사 생성자
    ~MyString();
    int length() const;
    /* 2에서의 추가 내용 */
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    /* 2에서의 추가 내용 */
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
};

MyString::MyString(char c){
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length]; // 메모리 할당
    for (int i=0;i!=string_length;i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length]; // 메모리 할당
    for (int i=0;i<string_length;i++) string_content[i] = str.string_content[i];
}

MyString::~MyString() {delete[] string_content;}

int MyString::length() const {return string_length;}

void MyString::print() const{
    for (int i=0;i<string_length;i++){
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    for(int i=0;i<string_length;i++){
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}

/* 2에서의 추가 내용 */
MyString& MyString::assign(const MyString& str){
    if (str.string_length > memory_capacity){ // 새로 배정된 단어 길이가 메모리 용량보다 크다면
        // 메모리를 재할당한다.

        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i=0;i!=str.string_length;i++){
        string_content[i] = str.string_content[i];
    }

    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str){
    int str_length = strlen(str);
    if (str_length > memory_capacity){ // 새로 배정된 단어 길이가 메모리 용량보다 크다면
        // 메모리를 재할당한다.
        
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i=0; i!= str_length; i++){
            string_content[i] = str[i];
        }

        string_length = str_length;

        return *this;
}

int MyString::capacity() const {return memory_capacity;}
void MyString::reserve(int size){
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i=0;i!=string_length;i++){
            string_content[i] = prev_string_content[i];
        }

        delete[] prev_string_content;
    }

    // 예약하려는 size가 memory_capacity가 클 때만 동작
}

int main()
{
    MyString str1("very very very long string");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String Length : " << str1.length() << std::endl;
    str1.println();
}