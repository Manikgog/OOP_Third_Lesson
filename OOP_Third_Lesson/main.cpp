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


int main() {
	std::vector<int> marks = { 5, 4, 3, 2 };
	Professor p("Instein", 56, "doctor");
	Student s("Mak", 43, marks);
	p.ShowData();
	s.ShowData();


	return 0;
}