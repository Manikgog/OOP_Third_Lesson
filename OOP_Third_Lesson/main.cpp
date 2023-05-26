#include <iostream>
#include <string>
#include <vector>

class Person {
protected:
	std::string name;
	int age;

public:
	Person() : name(""), age(0) {}
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	virtual void ShowData() = 0;
	/*
	void ShowData() {
		std::cout << "Name: " << name << '\n';
		std::cout << "Age: " << age << '\n';
	}
	*/

};

class Student : public Person {
private:
	std::vector<int> _marks;

public:
	Student() {}
	Student(std::string name, int age, std::vector<int>& marks) : Person(name, age), _marks(marks) {}

	void ShowData() override {
		std::cout << "Student name: " << name << '\n';
		std::cout << "Student age: " << age << '\n';
		std::cout << "Student marks: ";
		bool is_first = true;
		for (const auto& it : _marks) {
			if (!is_first)
				std::cout << ", ";
			is_first = false;
			std::cout << it;
		}
		std::cout << "\n\n";
	}

};

class Professor : public Person {
private:
	std::string _degree;

public:
	Professor() {
		name = "";
		age = 0;
	}
	Professor(std::string name, int age, std::string degree) : Person(name, age), _degree(degree) {}

	void ShowData() override {
		std::cout << "Professor name: " << name << '\n';
		std::cout << "Professor age: " << age << '\n';
		std::cout << "Professor degree: " << _degree << "\n\n";

	}

};

class Worker {
private:
	std::string _name;
	int _age;
	float _bill;


public:
	Worker(std::string name, int age) : _name(name), _age(age), _bill(0) {}

	std::string GetName() {
		return _name;
	}

	int GetAge() {
		return _age;
	}

	float GetBill() {
		return _bill;
	}

	virtual void Work() = 0;	// Чистая виртуальная функция
	void Bill(int hoursOfWork) {
		_bill = 250 * hoursOfWork;
		std::cout << "Salary: " << _bill << std::endl;
	}

};

class Buyer : public Worker {

public:
	Buyer(std::string name, int age) : Worker(name, age) {}

	void Work() override {
		std::cout << Worker::GetName() << " buying something" << std::endl;
	}
};

class Bilder : public Worker {

public:
	Bilder(std::string name, int age) : Worker(name, age) {}

	void Work() override {
		std::cout << Worker::GetName() << " bilding\
 something." << std::endl;
	}
};


int main() {
	/*std::vector<int> marks = { 5, 4, 3, 2 };
	Professor p("Instein", 56, "doctor");
	Student s("Mak", 43, marks);
	p.ShowData();
	s.ShowData();*/

	Buyer buyer("Joe", 35);
	Bilder bilder("Donald", 34);
	buyer.Work();
	bilder.Work();
	buyer.Bill(24);
	bilder.Bill(25);


	return 0;
}