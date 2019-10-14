//(실습 2) 아래 코드에서 Derived class는 Base1, Base2를 상속 받는다.
//이때, 각 클래스의 생성자가 호출되는 순서는 무엇인가? 

#include <vector>
#include <string>
#include <iostream>

class Base1 {
public:
	Base1(int n) : vector_(n, 3) {
		printf("hello\n");	//확인해보기
	}
	//.....
private:
	std::vector<char> vector_;
};

class Base2 {
public:
	Base2(int n) : vector_(n, 3) {
		printf("hello2\n");
	}
	//.....
private:
	std::vector<char> vector_;
};

class Derived : public Base1, Base2 {
	//위의 상속의 순서로 따라가는 것, 부모에 대한 객체를 먼저 만들어줌
	//그 다음에 자식 클래스의 생성자를 호출
public:
	Derived(const std::string& str) : Base2(1024), Base1(512)
	{
		i = 0;
	}
	// 값 초기화 순서로 따라가는게 아님
private:
	std::string str_;
	int i = 0;
};
int main() {
	Derived drv("eded");
	return 0;
}


