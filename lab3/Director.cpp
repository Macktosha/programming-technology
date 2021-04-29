#include <iostream>
#include <fstream>
#include "Director.h"

using namespace std;
Director::Director() {

}


Director::Director(std::string chair)
{
	this->cathedra = chair;
}

Director::~Director(){}

void Director::setDirector()
{
	cout << "Please, enter necessary info about chairman" << endl;

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

	cout << "\nCathedra: ";
	cin >> this->cathedra;

	fstream fs;
	fs.open("directors.txt", fstream::app);

	if (!fs.is_open()) {
		cout << "couldn't open this file!" << endl;
		system("exit");
	}
	fs << "\n" << this->name << "\n" << this->surname << "\n" << this->last_name << "\n" << this->b_day << "\n" << this->b_month << "\n" << this->b_year << "\n" << this->cathedra;

	fs.close();
}

void Director::print()
{
	cout << "  Professor: " << this->name << " " << this->surname << " " << this->last_name << endl;
	cout << "Date of birth: " << this->b_day << "." << this->b_month << "." << this->b_year << endl;
	cout << "Cathedra: " << this->cathedra << endl;
	cout << "\n";
}

int Director::recover()
{
	int cnt3 = 0;
	ifstream stFile;
	stFile.open("directors.txt");
	if (!stFile.is_open()) {
		cout << "couldn't open this file!" << endl;
		system("exit");
	}

	if (stFile.peek() == EOF)
	{
		cout << "File <directors.txt> is empty yet, but you can change it)" << endl;
		return cnt3;
	}
	else {
		while (!stFile.eof()) {
			stFile >> this[cnt3].name >> this[cnt3].surname >> this[cnt3].last_name >> this[cnt3].b_day >> this[cnt3].b_month >> this[cnt3].b_year >> this[cnt3].cathedra;
			cnt3++;
		}
	}
	stFile.close();
	return cnt3;
}
void Director::is_empty() {
	fstream file;
	file.open("directors.txt");
	if (file.peek() == EOF)
		cout << "File <directors.txt> is empty" << endl;
	file.close();
}
