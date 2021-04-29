#pragma once
#include "queue.h"

class private_inheritor : private Queue { //наследник с private
public: 
	float lab_task();
	bool is_empty();
	void push(int var);
	int pop();
	void print_q();
	void copy_q(private_inheritor& queue);
	void merge_q(private_inheritor& Q1, private_inheritor& Q2);
};

class protected_inheritor : protected Queue {//наследник с protected
public:
	float lab_task();
	bool is_empty();
	void push(int var);
	int pop();
	void print_q();
	void copy_q(protected_inheritor& queue);
	void merge_q(protected_inheritor& Q1, protected_inheritor& Q2);
};

class public_inheritor : public Queue { 
public:
	float lab_task();

};