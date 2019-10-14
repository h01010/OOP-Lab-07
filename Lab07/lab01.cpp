//(실습 0) 아래 코드를 실행/분석해 보세요
//(operator overloading과 conversion에 대해 복습).

#include<iostream>
#include <string>//추가해야합니다

class MyData {
	int number;
	std::string strNumber;
public:
	MyData(int data, std::string str) : number(data), strNumber(str) {}
	operator int() { return number; }
	operator std::string() { return strNumber; }

	int operator++ (int) {	//int있으면 후위
		int temp = number;
		number++;
		return temp;
	}
	//둘 다 후위연산자인지 전위인지 모름, 그냥 외워야 함
	int operator++() {		//비워두면 전위
		return ++number;
	}

	friend std::ostream& operator<<(std::ostream&, MyData &);
	//myNumber가 private이기때문에, 외부에서 참조가능하게 바꾸어줌

};

std::ostream& operator<<(std::ostream& os, MyData & md) {
	return os << "This number is: " << md.strNumber << "\n";
}
int main() {
	MyData mydata(1, "one");		//객체 생성
	std::string strNum = mydata;	//stringNum에 넣어줌, string에 들어감
	int intNum = mydata;

	std::cout << strNum << std::endl;
	std::cout << intNum << std::endl;
	std::cout << mydata++ << std::endl; // 1
	std::cout << ++mydata << std::endl; // 3
	std::cout << mydata;

	//cout도 클래스 이름
}