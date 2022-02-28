// 복소수 클래스는 std::complex를 통해 제공중
#include <iostream>

class Complex{
private:
    double real, img;

public:
    Complex(double real, double img) : real(real), img(img) {}

    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);

    Complex operator=(const Complex& c);
    Complex operator+=(const Complex& c);
    Complex operator-=(const Complex& c);
    Complex operator*=(const Complex& c);
    Complex operator/=(const Complex& c);

    void println(){
        std::cout << "(" << real << ", " << img << " ) " << std::endl;
    }
};

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
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c(0.0, 0.0);
    c = a * b + a / b + a + b;
    c.println();

    a += b;
    a.println();
    b.println();
}