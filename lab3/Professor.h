#pragma once
#include "Person.h"

class Professor: public Person {
public:
	void print() override;
	int recover()override;
	void is_empty()override;
	Professor();
	Professor(std::string subj, int qtty);
	~Professor();

	void setProfessor();
private:
	std::string disciplines;
	int q_stud;

};