// 타입을 가지고 컴파일 타임에 생성되는 코드로 프로그래밍하는 것
// 분수의 사칙연산

#include <iostream>
#include <typeinfo>

template <int X, int Y>
struct GCD {
    static const int value = GCD<Y, X%Y>::value;
    // static const를 사용하는 이유
    // 1. 클래스 멤버 중 클래스 자체에서 초기화할 수 있는 멤버의 타입 중 유일함
    // 2. 이 클래스는 이 것이다라는 의미를 가장 잘 나타냄
};

template <int X>
struct GCD<X, 0> {
    static const int value = X;
};


template<int N, int D = 1>
struct Ratio {
private:
    const static int _gcd = GCD<N, D>::value; // 최대공약수
public:
    typedef Ratio<N / _gcd, D / _gcd> type; // 자기 자신을 가리키는 타입
    static const int num = N / _gcd; // 분자
    static const int den = D / _gcd; // 분모
};

template<class R1, class R2>
struct _Ratio_add{
    typedef Ratio<R1::num*R2::den + R2::num*R1::den, R1::den*R2::den> type;
};

template<class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template<class R1, class R2>
struct _Ratio_subtract{
    typedef Ratio<R1::num*R2::den - R2::num*R1::den, R1::den*R2::den> type;
};

template<class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template<class R1, class R2>
struct _Ratio_multiply{
    typedef Ratio<R1::num*R2::num, R1::den*R2::den> type;
};

template<class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template<class R1, class R2>
struct _Ratio_divide{
    typedef Ratio<R1::num*R2::den, R1::den*R2::num> type;
};

template<class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};
int main()
{
    std::cout << "gcd(36, 24) : " << GCD<36, 24>::value << std::endl;

    using r1 = Ratio<2, 3>;
    using r2 = Ratio<3, 2>;

    using r3 = Ratio_add<r1, r2>;
    std::cout << r3::num << "/" << r3::den << std::endl;

    using r4 = Ratio_multiply<r1, r3>;
    std::cout << r4::num << "/" << r4::den << std::endl;

    return 0;
}