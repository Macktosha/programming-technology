#pragma once

typedef struct element
{
	struct element* prev = 0;
	int value = 0;
}element;

class Queue {
	element* end = 0;
protected:
	int size;
	element* get_end();
public:
	Queue();
	~Queue();
	bool is_empty();
	void push(int var);
	int pop();
	void print_q();
	void copy_q(Queue& queue);
	void merge_q(Queue& Q1, Queue& Q2);
	
};
