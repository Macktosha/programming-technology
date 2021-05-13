#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include <string>

using namespace std;

template <typename T>

void fill_array(T* array, int size) {
	cout << "Please, fill your array" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "[" << i << "] = "; cin >> array[i];
		cout << "\n";
	}
}

//template <> void fill_array(char** array, int size)
//{
//	char tmp[100];
//	int len = 0;
//	for (int i = 0; i < size; ++i) {
//		cout << "[" << i << "] = "; 
//cin.getline(tmp,100);
//		len = strlen(tmp) + 1;
//		array[i] = new char[len];
//		strcpy(array[i], tmp);
//		cout << "\n";
//	}
//}