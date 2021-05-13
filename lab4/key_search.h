#pragma once
#include<iostream>

using namespace std;



template <typename T> void key_search(T* array, int size, T key)
{
	bool flag = false;
	cout << "In searching of key index:..." << endl;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == key) {
			cout << "<" << i << ">" << endl;
			flag = true;
		}
	}
	
	if (flag == false)
	{
		cout << "Couldn't find key index" << endl;
	}

}
