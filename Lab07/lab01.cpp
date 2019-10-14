//(�ǽ� 0) �Ʒ� �ڵ带 ����/�м��� ������
//(operator overloading�� conversion�� ���� ����).

#include<iostream>
#include <string>//�߰��ؾ��մϴ�

class MyData {
	int number;
	std::string strNumber;
public:
	MyData(int data, std::string str) : number(data), strNumber(str) {}
	operator int() { return number; }
	operator std::string() { return strNumber; }

	int operator++ (int) {	//int������ ����
		int temp = number;
		number++;
		return temp;
	}
	//�� �� �������������� �������� ��, �׳� �ܿ��� ��
	int operator++() {		//����θ� ����
		return ++number;
	}

	friend std::ostream& operator<<(std::ostream&, MyData &);
	//myNumber�� private�̱⶧����, �ܺο��� ���������ϰ� �ٲپ���

};

std::ostream& operator<<(std::ostream& os, MyData & md) {
	return os << "This number is: " << md.strNumber << "\n";
}
int main() {
	MyData mydata(1, "one");		//��ü ����
	std::string strNum = mydata;	//stringNum�� �־���, string�� ��
	int intNum = mydata;

	std::cout << strNum << std::endl;
	std::cout << intNum << std::endl;
	std::cout << mydata++ << std::endl; // 1
	std::cout << ++mydata << std::endl; // 3
	std::cout << mydata;

	//cout�� Ŭ���� �̸�
}