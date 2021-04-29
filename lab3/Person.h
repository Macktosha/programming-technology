#pragma once
#include <string>
class Person//абстрактный базовый класс Персона 
{
public:
	virtual void print() = 0;
	virtual ~Person();
	virtual int recover() = 0;
	virtual void is_empty() = 0;
	
protected:
	std::string name;
	std::string surname;
	std::string last_name;
	int b_day;
	int b_month;
	int b_year;
};


