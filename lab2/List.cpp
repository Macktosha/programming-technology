#include "List.h"
#include <iostream>

using namespace std;

  List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
       return count;
}

List& List::operator++()//добавление в конец префикс
{

    int data = 0;
    cout << "Enter new data to add into the tail of the list " << endl;
    cin >> data;
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->pNext = NULL;
   
    if (count == 0)
    {
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;

        while (p->pNext != NULL)
            p = p->pNext;

        p->pNext = temp;
    }
    count++;
    return *this;
}

List& operator--(List& L1) {//удаление из конца префикс френд

    if (L1.count == 0) {
        cout << "List is empty" << endl;
        return L1;
    }
 
    else if (L1.count == 1)
    {
        Element* temp = L1.Head;
        delete temp;
        L1.Head=L1.Tail = NULL;
        cout << "Now this list is empty" << endl;
    }
    else {

        Element* one = L1.Head;
        Element* two = L1.Head->pNext;
        while (two->pNext != NULL) {
            two = two->pNext;
            one = one->pNext;
        }
        one->pNext = NULL;
        delete two;
    }
    L1.count--;
    return L1;
}

List& List::operator--(int) {//удаление из начала постфикс

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->pNext;
    // удаляем бывший головной элемент
    delete temp;
    if (count == 1)
        cout << "Now this list is empty" << endl;

        count--;
     
    return *this;
}

List& operator++(List& L2, int)//добавление в начало постфикс френд
{
    int data1 = 0;
    cout << "Enter new data to add into the head of the list " << endl;
    cin >> data1;
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data1;
    // следующий элемент отсутствует
    temp->pNext = L2.Head;
    
    if (L2.Head == NULL)
    {
        temp->pNext = NULL;
        L2.Head =L2.Tail= temp;
    }
    else  if (L2.Head != NULL)
    {
        temp->pNext = L2.Head;
        L2.Head = temp;
    }
    L2.count++;
    return L2;
}

void List::Del_head()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->pNext;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del_head();
}

void List::Print_list()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;
    
    while (temp!= 0)
    {
        // Выводим данные
        cout << temp->data << " " << endl;;
        // Переходим на следующий элемент
        temp = temp->pNext;
       
    }

    cout << "Tail of the list\n\n" << endl;
}