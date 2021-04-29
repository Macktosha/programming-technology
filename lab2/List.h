#pragma once 


typedef struct Element
{
	int data;
	Element* pNext;
}Element;
	
class List
{
public: 
	 List();
	~List();

	
	
	// (Удаляется головной элемент)
	void Del_head();
	// Удаление всего списка
	void DelAll();

	List& operator++();//добавление в конец префикс
	
	friend List& operator--(List& L1);//префикс удаление из конца 

	friend List& operator++(List& L2, int);//добавление в начало постфикс

	List& operator--(int);//удаление из начала постфикс
	
	void Print_list();//Печать списка

	// Получение количества элементов, находящихся в списке
	int GetCount();

private:
	Element* Head;
	Element* Tail;

	int count;

	
	
};


