//(�ǽ� 1) �Ʒ� �ڵ��� ������ ���� ������ ������ ������.
//Derived Class�� �����Ͽ� ������ �ǵ��� �غ�����. 

class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};

class Derived : public  Base {	//������ protected���µ�, public���� ������(������������)
	//Base�� ��ӹ��� Derived
	//protected�� �ڽ�Ŭ���� ���ο����� ���� �����ϵ��� ��
	//main������ ������ �� ����
public:
	void func_3() {
		func_1();
		func_2();
	}
};

int main() {
	Derived d;
	d.func_3(); //func_3�� �θ��� Derived�� ���� func_1�� ���� ����
	d.func_1();
}
