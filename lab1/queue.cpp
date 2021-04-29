#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue()
{
	size = 0;
}

Queue::~Queue() {
	while (size > 0) { //последовательное высвободение памяти
		element* tmp = end;
		end = tmp->prev;
		delete[] tmp;
		--size;
	}
}

element* Queue::get_end() { return end; }//метод для получения конца очереди

void Queue::push(int var) {
	
		if (end == nullptr) //если элементов нет
		{
			end = new element;
			end->prev = nullptr;
			end->value = var;
		}
		else
		{
			element* tmp = new element;//если были элементы
			tmp->prev = end;
			tmp->value = var;
			end = tmp;
		}
		size++;
	}


	int Queue::pop()
	{
	
		element* tmp = end;

		if (size == 0) {

			cout << "Queue is empty" << endl;
			return 1;
		}

		if (size == 1) {

			tmp=nullptr;
			size--;
			cout << "Queue is empty" << endl;
			end = tmp;
			return 1;

		}

		while (tmp->prev->prev != 0) {

			tmp = tmp->prev;

		}

		element* popElem = tmp->prev;

		tmp->prev = 0;

		delete popElem;

		size--;

		cout << "caught..." << endl;
		return 1;
	}

	void Queue::print_q() {
		element* tmp = end;

		if (tmp != nullptr) {
			cout << "\n The end of the queue" << endl;
			while (tmp != nullptr) {
				cout << "* " << tmp->value << " *" << endl;
				tmp = tmp->prev;

			}
			if (tmp == nullptr)
				cout << " Beginning of the queue" << endl;
		}
		else cout << "\nThe queue is empty" << endl;
	}

	void Queue::copy_q(Queue& queue) {

		int* copy_value = new int[queue.size];

		element* tmp = queue.end;

		for (int i = queue.size - 1; i >= 0; i--) {

			copy_value[i] = tmp->value;

			tmp = tmp->prev;

		}

		for (int i = 0; i < queue.size; i++)
			this->push(copy_value[i]);


		delete[] copy_value;

		cout << "Queue was copied" << endl;
	}

	void Queue::merge_q(Queue& Q1, Queue& Q2)
	{
		if (Q2.end == nullptr) { copy_q(Q2); }

		element* tmp1 = Q1.end;

		int* newValue1 = new int[Q1.size];

		element* tmp2 = Q2.end;

		int* newValue2 = new int[Q2.size];

		int i;

		for (i = Q1.size - 1; i >= 0; i--) {

			newValue1[i] = tmp1->value;

			tmp1 = tmp1->prev;

		}

		for (i = 0; i < Q1.size; i++) {

			this->push(newValue1[i]);

		}

		delete[] newValue1;

		for (i = Q2.size - 1; i >= 0; i--) {

			newValue2[i] = tmp2->value;

			tmp2 = tmp2->prev;

		}

		for (i = 0; i < Q2.size; i++) {

			this->push(newValue2[i]);

		}

		delete[] newValue2;

		cout << "Queue was merged" << endl;

		this->print_q();

	}

	bool Queue::is_empty() //проверка пустая ли очередь 
	{
		if (!size) return true; 
		else return false;
	}