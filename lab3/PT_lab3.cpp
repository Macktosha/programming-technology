#include <iostream>
#include <fstream>

#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Director.h"

using namespace std;


int main()
{
    
    Student *st=new Student[27];
    Professor* prof = new Professor[15];
    Director* dir = new Director[10];

    char choice1, choice2;
    choice1 = choice2 = NULL;

    int st_cnt = st->recover();
    int prof_cnt = prof->recover();
    int dir_cnt = dir->recover();

    do
    {
        cout << " Choose the command:" << endl;
        cout << "1 - View persons\n2 - Add person\n3 - Delete all data\n\t0 - Exit" << endl;
        cin >> choice1;
        system("cls");
        switch (choice1)
        {
        case '1':
            cout << "Which type would you like to view?\n1 - Students\n2 - Professors\n3 - Directors\n\t0 - None" << endl;
            cin >> choice2;
            switch (choice2)
            {
            case '1':
                st->is_empty();
                for (int i = 0; i < st_cnt; ++i)
                    st[i].print();
                break;
            case '2':
                prof->is_empty();
                for (int i = 0; i < prof_cnt; ++i)
                    prof[i].print();
                break;
            case '3':
                dir->is_empty();
                for (int i = 0; i < dir_cnt; ++i)
                    dir[i].print();
                break;
            case '0':
                break;
            default:
                cout << "Incorrect value or undefined error" << endl;
                break;
            }
            break;
        case '2':
            cout << "Which person would you like to add?" << endl;
            cout << "1 - Students\n2 - Professors\n3 - Directors\n\t0 - None" << endl;
            cin >> choice2;
            switch (choice2)
            {
            case '1':
                st[st_cnt++].setStudent();
                break;
            case '2':
                prof[prof_cnt++].setProfessor();
                break;
            case '3':
                dir[dir_cnt++].setDirector();
                break;
            case '0':
                break;
            default:
                cout << "Incorrect value or undefined error" << endl;
                break;
            }
            break;
        case '3':
            cout << "Are you sure to delete all data?\n1 - Yes\n2 - No" << endl;
            cin >> choice2;
            if (choice2=='1') {
                fstream ss, pp, dd;
                ss.open("students.txt", ios::out|ios::trunc);
                pp.open("professors.txt", ios::out | ios::trunc);
                dd.open("directors.txt", ios::out | ios::trunc);
                ss.close();
                pp.close();
                dd.close();
                break;
            }
            else
                break;
        case '0': 
            break;
        default:
            cout << "Incorrect value or undefined error" << endl;
            break;
        }
    } while (choice1!='0');
    
    
   delete[]st;
   delete[]prof;
   delete[]dir;
    return 0;
}
