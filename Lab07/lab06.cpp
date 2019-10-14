/*
(실습 3.1) 위 코드에서는 Manager, Intern, Janitor 타입의 오브젝트들을 관리하기 위해,
각 오브젝트와 동일한 타입을 가지는 배열 (managelist, internlist, janitorlist) 을 생성하였다.
하지만 이러한 방식의 문제점은, Employ class를 상속받는 새로운 class 타입이 추가 (예: Supervisor) 될 때마다, 새롭게 추가된 class 타입을 저장하기 위한 배열( 예: supervisorlist)을 생성해야 한다는 점이다.

이러한 문제점은 업캐스팅 (Upcasting)을 활용하여 해결가능하다.
즉, Employ의 주소를 저장하기 위한 배열을 생성하고, Manager, Intern, Janitor 오브젝트들을 해당 배열에서 통합 관리할 수 있다.
아래 코드가 정상 동작할 수 있도록 코드를 수정하세요 (실습 3과 실행 결과가 동일해야 한다).

위 코드는 관리해주어야하기에 3.1처럼 개선
여기서는 클래스를 한 배열에 통합하여 관리
*/

#include <iostream>
#include <string>

class Employee {
protected:
	std::string name;
	int age;

public:
	Employee(std::string name, int age) : name(name), age(age) {}

	virtual void showInfo() { std::cout << "Name:" << name << ", Age: " << age << std::endl; }	//자식클래스에서 재정의하기를 기다리고 있는 상황

	//계속 윗 출력문만 출력중임
	//즉 upcasting은 완료됐지만, 제대로 되지 않은 상태
};

class Manager : public Employee {
	int managerBonus;
public:
	Manager(int managerBonus, std::string name, int age) : managerBonus(managerBonus), Employee(name, age) {}

	void showInfo() { std::cout << "Manager Name:" << name << ", Age: " << age << ", managerBonus:" << managerBonus << std::endl; }
};

class Intern : public Employee {
	std::string majorName;
public:
	Intern(std::string major, std::string name, int age) : majorName(major), Employee(name, age) {}

	void showInfo() { std::cout << "Intern Name:" << name << ", Age: " << age << ", Major:" << majorName << std::endl; }
};

class Janitor : public Employee {
	int salary;
public:
	Janitor(int salary, std::string name, int age) : salary(salary), Employee(name, age) {}

	void showInfo() { std::cout << "Janitor Name:" << name << ", Age: " << age << ", Salary:" << salary << std::endl; }
};

int main() {

	Employee** employeelist = new Employee*[6];	//이미 upcasting을 했다 여기서
	//형변환해서 사용하는 것 upcasting

	employeelist[0] = new Manager(200, "James", 33);
	employeelist[1] = new Manager(150, "Chulsoo", 50);

	employeelist[2] = new Intern("security", "Minsu", 24);
	employeelist[3] = new Intern("HCI", "Yong", 19);
	employeelist[4] = new Janitor(100, "Black", 90);
	employeelist[5] = new Janitor(200, "White", 100);

	employeelist[0]->showInfo();
	employeelist[1]->showInfo();

	employeelist[2]->showInfo();
	employeelist[3]->showInfo();

	employeelist[4]->showInfo();
	employeelist[5]->showInfo();

	//3과 같은 결과가 나오게 하라
	//음....

	getchar();
	return 0;
}
