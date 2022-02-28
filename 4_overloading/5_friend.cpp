// 복소수 클래스는 std::complex를 통해 제공중
#include <iostream>
#include <string.h>

class Complex{
private:
    double real, img;
    double get_number(const char *str, int from, int to);

public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) { real = c.real, img = c.img;}
    Complex(const char* str);

    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);

    Complex operator=(const Complex& c);
    Complex operator+=(const Complex& c);
    Complex operator-=(const Complex& c);
    Complex operator*=(const Complex& c);
    Complex operator/=(const Complex& c);

    friend Complex operator+(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    // 클래스의 입장에서 프렌드 함수에게 모든 정보에 접근할 수 있도록 허가

    void println(){
        std::cout << "(" << real << ", " << img << " ) " << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Complex& c){
    os << "( " << c.real << " , " << c.img << " ) ";
    return os;
}

Complex operator+(const Complex& a, const Complex& b){
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}

Complex::Complex(const char* str){ // 4에서 새로 수정
    // 입력받은 문자열을 분석하여 실수 부분과 허수 부분 찾기
    // 문자열의 끝은 다음과 같음 "[부호](실수부)[부호]i(허수부)"
    // 맨 앞의 부호는 생략 가능
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 가장 기준이 되는 "i"의 위치 탐색
    int pos_i = -1;
    for (int i=0;i != end; i++){
        if (str[i] == 'i'){
            pos_i = i;
            break;
        }
    }
    // i가 없다면 이 수는 실수인 것이 확실
    if (pos_i == -1){
        real = get_number(str, begin, end - 1);
        return;
    }

    // i가 있다면 실수부와 허수부를 나눠 처리한다.
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

double Complex::get_number(const char *str, int from, int to){
    bool minus = false;
    if (from > to) return 0; // 시작점이 끝점보다 큰 것을 방지

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool interger_part = true;
    for (int i = from; i <= to; i++){
        if (isdigit(str[i]) && interger_part){ // 소숫점 앞부분
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.')
            interger_part = false;
        else if (isdigit(str[i]) && !interger_part){ // 소숫점 뒷부분
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else break; // 그 이외의 이상한 문자가 올 경우
    }

    if (minus) num *= -1.0;

    return num;
}

Complex Complex::operator+(const Complex& c){
    Complex temp(real + c.real, img + c.img);
    return temp;
}


Complex Complex::operator-(const Complex& c){
    Complex temp(real - c.real, img - c.img);
    return temp;
}

Complex Complex::operator*(const Complex& c){
    Complex temp(real * c.real - img * c.img , real * c.img + img * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c){
    Complex temp((real * c.real + img * c.img) / (c.real * c.real + c.img * c.img), (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex Complex::operator=(const Complex& c){
    real = c.real;
    img = c.img;
    return *this; // 대입 연산 이후 다른 연산을 수행하지 않아 레퍼런스를 리턴하는 것이 효율적
}

Complex Complex::operator+=(const Complex& c){
    (*this) = (*this) + c;
    return *this;
}

Complex Complex::operator-=(const Complex& c){
    (*this) = (*this) - c;
    return *this;
}

Complex Complex::operator*=(const Complex& c){
    (*this) = (*this) * c;
    return *this;
}

Complex Complex::operator/=(const Complex& c){
    (*this) = (*this) / c;
    return *this;
}

int main()
{
    Complex a(0, 0);
    a = "-1.1+i3.923" + a;
    std::cout << "a : " << a << std::endl;
}