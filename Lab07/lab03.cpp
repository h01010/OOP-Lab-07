//(�ǽ� 2) �Ʒ� �ڵ忡�� Derived class�� Base1, Base2�� ��� �޴´�.
//�̶�, �� Ŭ������ �����ڰ� ȣ��Ǵ� ������ �����ΰ�? 

#include <vector>
#include <string>
#include <iostream>

class Base1 {
public:
	Base1(int n) : vector_(n, 3) {
		printf("hello\n");	//Ȯ���غ���
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
	//���� ����� ������ ���󰡴� ��, �θ� ���� ��ü�� ���� �������
	//�� ������ �ڽ� Ŭ������ �����ڸ� ȣ��
public:
	Derived(const std::string& str) : Base2(1024), Base1(512)
	{
		i = 0;
	}
	// �� �ʱ�ȭ ������ ���󰡴°� �ƴ�
private:
	std::string str_;
	int i = 0;
};
int main() {
	Derived drv("eded");
	return 0;
}


