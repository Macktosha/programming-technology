#include <iostream>
#include "legacy.h"

using namespace std;

int main()
{
    int choice, num, cnt,value,y;
   value = choice = cnt = y = num = 0;
   int x = 0;
   int dest = 0;
    int end = 1;
    bool exit = true;

    
    cout << "Please,enter the number of queues: " << endl; //количество очередей
 F1:
    cin >> num;
    if (num <= 0) {
        cout << "Attention! The number of queues is a positive value.\n\tPlease enter correct one: ";
        goto F1;
      }
    end = num;

    private_inheritor* Q = new private_inheritor[num];

    while (exit) {

    L1:
        system("cls");
        cout << "Which queue would you like to work with?" << endl;
        cout << "1 - " << end << endl;
        cin >> cnt;

        cnt--;

        if (cnt<0 || cnt + 1>end) {
            cout << "Incorrect number" << endl;
            goto L1;
        }

        system("cls"); //меню

        cout << "Queue #" << cnt + 1 << endl;
        cout << "\t1 - Add element" << endl;
        cout << "\t2 - Pop element" << endl;
        cout << "\t3 - Print queue" << endl;
        cout << "\t4 - Task button" << endl;
        cout << "\t5 - Copy queue" << endl;
        cout << "\t6 - Merge queues" << endl;
        cout << "\t\t7 - Exit" << endl;
        cout << "\nEnter the command: ";

        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Please, enter value of a new element(Queue #" << cnt + 1 << "): ";
            cin >> value;
            Q[cnt].push(value);
            break;
        case 2:
            if (Q[cnt].is_empty()) {
                cout << "Empty queue" << endl;
                system("pause");
                break;
            }
            Q[cnt].pop(); break;
        case 3:
            if (Q[cnt].is_empty()) {
                cout << "Empty queue" << endl;
                system("pause");
                break;
            }
            Q[cnt].print_q();

            system("pause"); break;
        case 4:
            if (Q[cnt].is_empty()) {
                cout << "Empty queue" << endl;
                system("pause");
                break;
            }

            cout << "The result is: " << Q[cnt].lab_task() << endl;
            system("pause"); break;

        case 5:
            if (Q[cnt].is_empty()) {
                cout << "Empty queue" << endl;
                system("pause");
                break;
            }

            cout << "Choose the position to copy\n Range: 1 - " << end << endl;
            cin >> y;
            y -= 1;

            if (!Q[y].is_empty()) {
                cout << "Unable to copy into the queue with data" << endl;
                break;
            }

            Q[y].copy_q(Q[cnt]);

            system("cls");
            cout << "Result:" << endl;
            Q[y].print_q();

            system("pause");
            break;

        case 6:

        L2:
            cout << "With what queue would you like to merge?" << endl;
            cin >> x;

            if (Q[x - 1].is_empty()){//проверка на слияние с пустой очередью
        
        cout << "Unable to merge with an empty queue" << endl;
        system("pause");
        break;
    }
                
            
            if (x - 1 < 0 || x  > end) {//проверка на слияние с несуществующей очередью
                cout << "Incorrect value! Re-enter it" << endl;
                goto L2;
            }
               
        L3:

            cout << "To queue # " << endl;//проверка на слияние в несущ очередь или на слияние в себя же
            cin >> dest;
            
            if (dest - 1 < 0 || dest > end||dest-1==cnt) {
                cout << "Incorrect value! Re-enter it" << endl;
                goto L3;
            }

            if (Q[cnt].is_empty()) {
                cout << "Empty queue" << endl;
                system("pause");
                break;
            }

           
                Q[dest-1].merge_q(Q[cnt], Q[x-1]);
                system("pause");
                break;
            
            

        case 7: 
            exit = false;
            break;


        default:
            cout << "Incorrect input or undefined error" << endl;
            break;
        }

    }

    delete[] Q;
    return 0;
}
