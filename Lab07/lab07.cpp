//(실습4) 아래 코드를 실행하고 문제점을 찾아보세요.

#include <iostream>

class Parent {
	char *p;
public:
	Parent() {
		p = new char[10];
		std::cout << "Parent Constructor invocation" << std::endl;
	}
	virtual ~Parent() {
		delete[] p;
		std::cout << "Parent Destructor invocation" << std::endl;
	}
};

class Child : public Parent {
	char *c;
public:
	Child() : Parent() {
		c = new char[10];
		std::cout << "Child Constructor invocation" << std::endl;
	}
	~Child() {
		delete[] c;
		std::cout << "Child Destructor invocation" << std::endl;
	}
};
int main() {
	std::cout << "--- Case1: Normal Child instantiation ---" << std::endl;
	Child *c = new Child();
	delete c;	//제거를 해주어야함, 메모리 leak방지

	std::cout << "--- Case2: Parent pointer to Child ---" << std::endl;

	Parent *p = new Child();
	delete p;	//여기가 안되고있음, 부모를 먼저 죽였기에 자식을 지울 수 없음

	getchar();
}
//정답 : 부모의 소멸자를 virtual로 바꾸어 주면 됨
//소멸자는 반대, 자식을 먼저 죽이고, 부모를 다음에 죽임
//실행을 해보면 알 수 있음