#pragma once
#include <iostream>

template <class T> class My_set {
private:
	T* body;
	int size;

public:

	My_set()
	{
		bool flag = true;
		while (flag)
		{
			try {
				cout << "\nPlease, enter the size of array" << endl;
				cin >> this->size;
				if (this->size < 0 || cin.fail())
					throw "incorrect size";
				break;
			}
			
			catch (const char* exc)
			{
				
				cerr<< exc << endl;
				cin.clear();
				continue;
			}
			
		}
		body = new T[this->size];

		cout << "Fill the set" << endl;

		for (int i = 0; i < this->size; i++)
		{
			cout << "[" << i << "] =";
			cin >> body[i];
			cout << "\n";
		}
	}

	~My_set()
	{
		delete[]body;
	}

	 T& operator[](int index)
	{
		 try {
			 if (index<0 || index>size - 1)
				 throw "There is no object with this index in this set";
			 return this->body[index];
		 }
			 
		 
		 catch (const char* exc)
		 {
			 cout << exc << endl;
		 }
		 
	}



	 void print()
	{
		 try
		 {

		if (size == 0)
			throw "Set is empty\n";
		else {
			for (int i = 0; i < this->size; ++i)
			{
				cout << this->body[i] << ", ";
			}
			cout << "\n";
		}
		}
		 catch (const char* excep) {
			 cout << excep;
		 }
	}

	 bool operator==(My_set& tmp)
	{
		 
		 if (this->size != tmp.size) {
			 cout << "You cannot compare sets with different sizes" << endl;
			 return false;
		 }
		 else {
			 for (int i = 0; i < size; ++i)
			 {
				 if (this->body[i] != tmp.body[i])
					 return false;
			 }
		 }
		 
			
			 return true;
		 
	}

    bool operator!=(My_set& tmp2)
	{
		try {
			if (this->size != tmp2.size)
				throw "You cannot compare sets with different sizes";
			else {
				for (int i = 0; i < size; ++i)
				{
					if (this->body[i] != tmp2.body[i])
						return true;
				}
			}
			return false;
		}
		catch (const char* exc) {
			cout << exc << endl;
		}
	}
};