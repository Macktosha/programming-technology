#pragma once
#include "Person.h"

class Student : public Person {
public:
	void print() override;
	int recover()override;
	void is_empty()override;
	Student();
	Student(int group, std::string enroll, float ave_scr);
	~Student();
	void setStudent();
private:

	int n_group;
	std::string enter_d;
	float score;

};