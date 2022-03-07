#include <iostream>
#include <string>
#include <cstring>

size_t GetStringSize(const char* s) {return strlen(s); }
size_t GetStringSize(const std::string& s) {return s.size();}

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs){
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str) {return;}

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs){
    concat_str->append(s);
    AppendToString(concat_str, strs...);
}

std::string StrCat(const String& s, Strings... strs){
    return std::string(s) + StrCat(strs...); // 재귀 방식으로 호출
}

int main()
{
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"), " ", std::string("sentence"));
}