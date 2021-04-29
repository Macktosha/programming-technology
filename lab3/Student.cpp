
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student() {
	n_group = 0;
	score = 0.0;
}
Student::Student(int group, std::string enroll, float ave_scr) {
	this->n_group = group;
	this->enter_d = enroll;
	this->score = ave_scr;
}

void Student::setStudent() {
	cout << "Please enter necessary info about student" << endl;

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

	cout << "\nEnter the group number:  ";
	cin >> this->n_group;

	cout << "\nEnter the date of enrollment:  ";
	cin >> this->enter_d;

	cout << "\nAverage score:  ";
	cin >> this->score;

	fstream fs;
	fs.open("students.txt", fstream::app);

	if (!fs.is_open()) {
		cout << "couldn't open this file!" << endl;
		system("exit");
	}
	fs <<"\n"<< this->name <<"\n"<< this->surname <<"\n"<< this->last_name << "\n" << this->b_day << "\n" << this->b_month << "\n" << this->b_year << "\n" << this->n_group << "\n" << this->enter_d << "\n" << this->score ;

	fs.close();

}

Student::~Student() {}

void Student::print() { 
	cout << "  Student: " << this->name <<" "<< this->surname <<" "<< this->last_name<<endl;
	cout << "Date of birth: " << this->b_day << "." << this->b_month << "." << this->b_year << endl;
	cout << "Group #: " << this->n_group << endl;
	cout << "Enter date: " << this->enter_d << endl;
	cout << "Average score:" << this->score << endl;
	cout << "\n\n";

}

int Student::recover() {
	int cnt1 = 0;
	ifstream stFile;
	stFile.open("students.txt");
	if (!stFile.is_open()) {
		cout << "couldn't open this file!" << endl;
		system("exit");
	}
	
	 if (stFile.peek() == EOF)
	 {
		 cout << "File <stuents.txt> is empty yet, but you can change it)" << endl;
		 return cnt1;
	}
	 else {
		 while (!stFile.eof()) {
			 stFile >> this[cnt1].name >> this[cnt1].surname >> this[cnt1].last_name >> this[cnt1].b_day >> this[cnt1].b_month >> this[cnt1].b_year >> this[cnt1].n_group >> this[cnt1].enter_d >> this[cnt1].score;
			 cnt1++;
		 }
	 }
	stFile.close();
	return cnt1;
}

void Student::is_empty() {
	fstream file;
	file.open("students.txt");
	if (file.peek() == EOF)
		cout << "File <stuents.txt> is empty" << endl;
	file.close();
}