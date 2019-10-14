//(실습 1) 아래 코드의 컴파일 에러 원인을 생각해 보세요.
//Derived Class를 수정하여 컴파일 되도록 해보세요. 

class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};

class Derived : public  Base {	//원래는 protected였는데, public으로 고쳤음(시험출제가능)
	//Base를 상속받은 Derived
	//protected는 자식클래스 내부에서만 접근 가능하도록 함
	//main에서는 접근할 수 없다
public:
	void func_3() {
		func_1();
		func_2();
	}
};

int main() {
	Derived d;
	d.func_3(); //func_3을 부르면 Derived로 가서 func_1은 실행 가능
	d.func_1();
}
