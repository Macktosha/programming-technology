#include "List.h"
#include <iostream>

using namespace std;

  List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    count = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
       return count;
}

List& List::operator++()//���������� � ����� �������
{

    int data = 0;
    cout << "Enter new data to add into the tail of the list " << endl;
    cin >> data;
    // �������� ������ ��������
    Element* temp = new Element;

    // ���������� �������
    temp->data = data;
    // ��������� ������� �����������
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

List& operator--(List& L1) {//�������� �� ����� ������� �����

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

List& List::operator--(int) {//�������� �� ������ ��������

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->pNext;
    // ������� ������ �������� �������
    delete temp;
    if (count == 1)
        cout << "Now this list is empty" << endl;

        count--;
     
    return *this;
}

List& operator++(List& L2, int)//���������� � ������ �������� �����
{
    int data1 = 0;
    cout << "Enter new data to add into the head of the list " << endl;
    cin >> data1;
    // �������� ������ ��������
    Element* temp = new Element;

    // ���������� �������
    temp->data = data1;
    // ��������� ������� �����������
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
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->pNext;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del_head();
}

void List::Print_list()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;
    
    while (temp!= 0)
    {
        // ������� ������
        cout << temp->data << " " << endl;;
        // ��������� �� ��������� �������
        temp = temp->pNext;
       
    }

    cout << "Tail of the list\n\n" << endl;
}