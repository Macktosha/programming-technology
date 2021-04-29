#include <iostream>
#include "legacy.h"

using namespace std;

//********private part*******//


float private_inheritor::lab_task() {//среднее гармоническое для четных порядковых
	element* tmp = get_end();
	int tmp_size = size;
	int counter = 0;
	float sum = 0.0;
	

	do
	{
		if (tmp_size % 2 == 0) {
			counter++;
			sum += (float)1 / (tmp->value);
		}
		tmp = tmp->prev;
		tmp_size--;
	} while (tmp_size > 0 && tmp->prev != nullptr && tmp != nullptr);
		
	
	return (float)counter / sum;
}

bool private_inheritor::is_empty() { return Queue::is_empty(); }
void private_inheritor::push(int var) {return Queue::push(var);}
int private_inheritor::pop() { return Queue::pop(); }
void private_inheritor::print_q() { return Queue::print_q(); }
void private_inheritor::copy_q(private_inheritor& queue) { return Queue::copy_q(queue); }
void private_inheritor::merge_q(private_inheritor& Q1, private_inheritor& Q2) {return Queue::merge_q(Q1, Q2);}


//********protected part**********//


float protected_inheritor::lab_task() {
	element* tmp = get_end();
	int tmp_size = size;
	int counter = 0;
	float sum = 0.0;

	do
	{
		if (tmp_size % 2 == 0) {
			counter++;
			sum += (float)1 / (tmp->value);
		}
		tmp = tmp->prev;
		tmp_size--;
	} while (tmp_size > 0 && tmp->prev != nullptr && tmp != nullptr);


	return (float)counter / sum;
}

bool protected_inheritor::is_empty() { return Queue::is_empty(); }
void protected_inheritor::push(int var) { return Queue::push(var); }
int protected_inheritor::pop() { return Queue::pop(); }
void protected_inheritor::print_q() { return Queue::print_q(); }
void protected_inheritor::copy_q(protected_inheritor& queue) { return Queue::copy_q(queue); }
void protected_inheritor::merge_q(protected_inheritor& Q1, protected_inheritor& Q2) { return Queue::merge_q(Q1, Q2); }

//*******public part******//

float public_inheritor::lab_task() {
	element* tmp = get_end();
	int tmp_size = size;
	int counter = 0;
	float sum = 0.0;

	do
	{
		if (tmp_size % 2 == 0) {
			counter++;
			sum += (float)1 / (tmp->value);
		}
		tmp = tmp->prev;
		tmp_size--;
	} while (tmp_size > 0 && tmp->prev != nullptr && tmp != nullptr);

	return (float)counter / sum;
}