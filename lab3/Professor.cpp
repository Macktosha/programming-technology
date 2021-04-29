#include <iostream>
#include <fstream>
#include "Professor.h"

using namespace std;

Professor::Professor()
{
	q_stud = 0;
}

Professor::Professor(std::string subj, int qtty)
{
	this->disciplines = subj;
	this->q_stud = qtty;
}

void Professor::setProfessor()
{
	cout << "Please, enter necessary info about professor" << endl;

	cout << "Name:  ";
	cin >> this->name;

	cout << "\nSurname:  ";
	cin >> this->surname;

	cout << "\nLast name:  ";
	cin >> this->last_name;

	cout << "\nDate of birth(format dd.mm.yyyy):  ";
	cin >> this->b_day;
	cin >> this->b_month;
	cin >> this->b_year;

	cout << "\nSubjects: ";
	cin >> this->disciplines;

	cout << "\nQuantity of students: ";
	cin >> this->q_stud;

	fstream fs;
	fs.open("professors.txt", fstream::app);

	if (!fs.is_open()) {
		cout << "couldn't open this file!" << endl;
		system("exit");
	}
	fs << "\n" << this->name << "\n" << this->surname << "\n" << this->last_name << "\n" << this->b_day << "\n" << this->b_month << "\n" << this->b_year << "\n" << this->disciplines << "\n" << this->q_stud;

	fs.close();
}

Professor::~Professor(){}

void Professor::print()
{
	cout << "  Professor: " << this->name << " " << this->surname << " " << this->last_name << endl;
	cout << "Date of birth: " << this->b_day << "." << this->b_month << "." << this->b_year << endl;
	cout << "Disciplines: " << this->disciplines << endl;
	cout << "Quantity of students: " << this->q_stud << endl;
	cout << "\n";
}

int Professor::recover()
{
	int cnt2 = 0;
	ifstream stFile;
	stFile.open("professors.txt");
	if (!stFile.is_open()) {
		cout << "couldn't open this file!" << endl;
		system("exit");
	}

	if (stFile.peek() == EOF)
	{
		cout << "File <professors.txt> is empty yet, but you can change it)" << endl;
		return cnt2;
	}
	else {
		while (!stFile.eof()) {
			stFile >> this[cnt2].name >> this[cnt2].surname >> this[cnt2].last_name >> this[cnt2].b_day >> this[cnt2].b_month >> this[cnt2].b_year >> this[cnt2].disciplines >> this[cnt2].q_stud ;
			cnt2++;
		}
	}
	stFile.close();
	return cnt2;
}
void Professor::is_empty() {
	fstream file;
	file.open("professors.txt");
	if (file.peek() == EOF)
		cout << "File <professors.txt> is empty" << endl;
	file.close();

}