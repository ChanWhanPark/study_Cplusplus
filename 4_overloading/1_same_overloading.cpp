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
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    char at(int i) const; // 임의의 문자를 리턴하는 함수

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    
    MyString& erase(int loc, int num);

    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;
    bool operator==(MyString& str);
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

char MyString::at(int i) const {
    if (i >= string_length || i < 0){ // 범위가 넘어갔을 때는,
        return 0;
    } else{
        return string_content[i]; // 특정 문자 리턴
    }
}

MyString& MyString::insert(int loc, const MyString& str){ // 새로운 문자열을 삽입하는 함수
    // 범위가 넘어갔을 때는 입력에 대해 삽입을 수행하지 않는다.
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.string_length > memory_capacity){
        // 새롭게 동적할당을 한다.

        // 새로운 동적할당 기법 : 메모리를 미리 할당할 때, 현재 메모리 크기의 2배 정도를 할당해 놓아
        // 잦은 할당/해제를 피하기 위한 메모리 할당과 많은 자원을 낭비하지 않는 두 조건을 모두 만족시킴
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;
    
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i=0;
        // 일단 insert되는 부분 직전까지의 내용 복사
        for (i=0;i<loc;i++){
            string_content[i] = prev_string_content[i];
        }
        // 새롭게 insert되는 문자열을 넣음
        for (int j=0;j!=str.string_length;j++){
            string_content[i+j] = str.string_content[j];
        }
        // 원 분자열의 나머지 뒷부분을 복사
        for (;i < string_length;i++){
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length += str.string_length;
        return *this;
    }

    // 초과하지 않는 경우, 굳이 동적할당을 할 필요가 없음
    // 효율적인 insert를 위해, 밀리는 부분을 먼저 뒤로 민다.
    for (int i=string_length-1;i>=loc;i--){
        // 뒤로 밀기
        string_content[i+str.string_length] = string_content[i];
    }
    // 그리고 insert되는 문자 다시 집어넣기
    for (int i=0;i<str.string_length;i++){
        string_content[i+loc] = str.string_content[i];
    }

    string_length += str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str){
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c){
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num){
    // loc의 앞 문자부터 num까지의 문자를 지운다.
    if (num < 0 || loc < 0 || loc > string_length) return *this;


    // 뒤의 문자들을 앞으로 끌고 옴
    for (int i=loc+num;i<string_length;i++){
        string_content[i-num] = string_content[i];
    }

    string_length -= num;
    return *this;
}

int MyString::find(int find_from, const MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i=find_from;i<string_length - str.string_length; i++){
        for (j=0;j<str.string_length;j++){
            if (string_content[i+j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1; // 찾지 못함
}

int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString& str) const{
    // (*this) - str을 수행하여 그 1, 0, -1로 결과를 리턴한다.
    for (int i=0;i<std::min(string_length, str.string_length); i++){
        if (string_content[i] > str.string_content[i]) return 1;
        else if (string_content[i] < str.string_content[i]) return -1;
    }

    // 앞 부분까지는 모두 같은 문자열인 상태에서
    if (string_length == str.string_length) return 0; // 길이가 같으면 같다는 것을 알림
    else if (string_length > str.string_length) return 1; 
    return -1;
}

bool MyString::operator==(MyString& str){
    return !compare(str); // str과 같으면 0을 출력
}

int main()
{
    MyString str1("a word");
    MyString str2("sentence");
    MyString str3("sentence");

    if (str1 == str2)
        std::cout << "str1 is same with str2" << std::endl;
    else
        std::cout << "str1 is different with str2" << std::endl;

    if (str2 == str3)
        std::cout << "str2 is same with str3" << std::endl;
    else
        std::cout << "str2 is different with str3" << std::endl;
}