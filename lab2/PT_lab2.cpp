#include <iostream>
#include "Time.h"
#include "List.h"

using namespace std;


int main()
{
	int choice, x, value, hh;
	int mm, ss;
	value = x = choice = hh = ss = mm = 0;
	int diff = 0;
	Time T,T1;
	List Lst;
	bool exit = true;
	bool exit2 = true;
	bool exit3 = true;
	do
	{
		exit = true;
		exit2 = true;
		exit3 = true;

		cout << "Choose the task: \n1 - List\n2 - Time\n\t3 - Exit" << endl;
		cin >> choice;
		while (choice < 0 || choice>3) {
			cout << "Incorrect input, enter again" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1: 
			while (exit3) {
				system("cls");
				cout << "Choose the command to work with List\n1 - Add element from the head\n2 - Delete element from the head\n3 - Add element to the tail\n4 - Delete element from the tail" << endl;
				cout << "5 - Print list\n\t6 - Exit" << endl;
				cin >> choice;

				while (choice < 0 || choice>6) {
					cout << "Incorrect input, enter again" << endl;
					cin >> choice;
				}

				switch (choice)
				{
				case 1:
					Lst++;
					system("pause");
					break;
				case 2:
					Lst--;
					system("pause");
					break;

				case 3:
					++Lst;
					system("pause");
				    break;

				case 4:
					--Lst;
					system("pause");
					break;
				case 5: 
					cout << "Elements:" << Lst.GetCount() << endl;
					Lst.Print_list();
					system("pause");
					break;
				case 6:
					exit3 = false;
					break;

				default:
					cout << "undefined error" << endl;
					exit3 = false;
					system("pause");
					break;
				}
			
			


			}
			break;

		case 2:
			system("cls");
			cout << "Please initialize Time data first!" << endl;
			cin >> hh;
			while (hh < 0 || hh>23) {
				cout << "Incorrect hour value, enter again" << endl;
				cin >> hh;
			}
			cin >> mm;
			while (mm < 0 || mm>59) {
				cout << "Incorrect minute value, enter again" << endl;
				cin >> mm;
			}
			cin >> ss;
			while (ss < 0 || ss>59) {
				cout << "Incorrect minute value, enter again" << endl;
				cin >> ss;
			}
			 T.setHour(hh);
			 T.setMin(mm);
			 T.setSec(ss);

			T.printTime();
			while (exit2) {
				cout << "\tChoose the command:\n1 - Increase time\n2 - Decrease time\n3 - Compare time\n4 - Change time\n\t5 - Exit" << endl;
				cin >> x;
				while (x < 0 || x>5) {
					cout << "Incorrect input, enter again" << endl;
					cin >> x;
				}
				switch (x)
				{
				case 1:
					system("cls");
					T.printTime();
					cout << "What param would you like to increase?\n1 - Hours\n2 - Minutes\n3 - Seconds\n\t4 - Exit" << endl;
					cin >> x;
					switch (x)
					{
					case 1:
						cout << "Enter the value: " << endl;
						cin >> diff;
						T + diff * 3600;
						cout << "Done!\n:  ";
						T.printTime();
						break;
					case 2:
						cout << "Enter the value: " << endl;
						cin >> diff;
						T + diff * 60;
						cout << "Done!\n  ";
						T.printTime();
						break;
					case 3:
						cout << "Enter the value: " << endl;
						cin >> diff;
						T + diff;
						cout << "Done!\n ";
						T.printTime();
						break;
					case 4:
						break;
					default:
						cout << "Incorrect input" << endl;
						break;
					}
					break;
				case 2:
					system("cls");
					T.printTime();
					cout << "What param would you like to decrease?\n1 - Hours\n2 - Minutes\n3 - Seconds\n\t4 - Exit" << endl;
					cin >> x;
					switch (x)
					{
					case 1:
						cout << "Enter the value: " << endl;
						cin >> diff;
						T - diff * 3600;
						cout << "Done!\n  ";
						T.printTime();
						break;
					case 2:
						cout << "Enter the value: " << endl;
						cin >> diff;
						T - diff * 60;
						cout << "Done!\n:  ";
						T.printTime();
						break;
					case 3:
						cout << "Enter the value: " << endl;
						cin >> diff;
						T - diff;
						cout << "Done!\n  ";
						T.printTime();
						break;
					case 4:
						break;
					default:
						cout << "Incorrect input" << endl;
						break;
					}
					break;
				case 3:
					cout << "Please enter your time to compare with\n  Current time: ";
					T.printTime();

				

					cin >> hh;
					while (hh < 0 || hh>23) {
						cout << "Incorrect hour value, enter again" << endl;
						cin >> hh;
					}
					cin >> mm;
					while (mm < 0 || mm>59) {
						cout << "Incorrect minute value, enter again" << endl;
						cin >> mm;
					}
					cin >> ss;
					while (ss < 0 || ss>59) {
						cout << "Incorrect minute value, enter again" << endl;
						cin >> ss;
					}

					T1.setHour(hh);
					T1.setMin(mm);
					T1.setSec(ss);

					if (T > T1) {
						cout << "System Time > Your Time" << endl;
					}

					else if (T < T1) {
						cout << "System Time < Your Time" << endl;
					}
					else if (T == T1) {
						cout << "Your and system time are equal" << endl;
					}

					else
					{
						cout << "undefined" << endl;
					}
					T1.printTime();

				

					break;

				case 4: 

					system("cls");
					cout << "Please enter NEW Time " << endl;
					cin >> hh;
					while (hh < 0 || hh>23) {
						cout << "Incorrect hour value, enter again" << endl;
						cin >> hh;
					}
					cin >> mm;
					while (mm < 0 || mm>59) {
						cout << "Incorrect minute value, enter again" << endl;
						cin >> mm;
					}
					cin >> ss;
					while (ss < 0 || ss>59) {
						cout << "Incorrect minute value, enter again" << endl;
						cin >> ss;
					}
					T.setHour(hh);
					T.setMin(mm);
					T.setSec(ss);

					T.printTime();
					break;

				case 5: 
					exit2 = false;
					break;
				}
				
			}
			break;
			case 3:
				exit = false;
				
			
		
		}


	} while (exit);
	

}

