#pragma once
#include "Person.h"
class Director : public Person
{
public:
	void print() override;
	int recover()override;
	void is_empty()override;
	void setDirector();
	Director();
	~Director();
	Director(std::string cathedra);

private:
	std::string cathedra;
};