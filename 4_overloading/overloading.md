### 정리
연산자 오버로딩에 대해 다루며 몇 가지 중요한 포인트들만 정리해보면,
> 두 개의 동등한 객체 사이에서 이항 연산자는 멤버 함수가 아닌 **외부 함수**로 오버로딩하는 것이 좋다.    
(ex. Complex의 operator+(const Complex&, const Complex&)와 같이)
> 두 개의 객체 사이의 이항 연산자이지만 한 객체만 값이 바뀌거나 동등하지 않는 이항연산자는 **멤버 함수**로 오버로딩하는 것이 좋다.
(ex. operator+=는 operator+=(const Complex&)로 오버로딩)
> 단항 연산자는 멤버 함수로 오버로딩하는 것이 좋다.
> 일부 연산자들은 반드시 멤버 함수로만 오버로딩해야 한다.