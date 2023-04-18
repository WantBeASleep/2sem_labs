#pragma once
#include <iostream>
#include "BinaryTree.hpp"
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

template <class T>
class BinaryHeap {
private:
	T* arr;
	int qty;
	//int height;
public:

	BinaryHeap() {
		arr = nullptr;
		qty = 0;
	}

	BinaryHeap(T* values, int size) {
		qty = size;
		arr = new T[size];
		for (int j = 0; j < size; j++) arr[j] = values[j];
		for (int i = 0; i < size; i++) {
			SiftDown(i);
		}
	}

	~BinaryHeap() {
		delete[] arr;
		qty = 0;
	}

	void Insert(T value) {
		if (!arr) arr = new T;
		qty++;
		arr[qty-1] = value;
		SiftUp(qty-1);
	}
	
	void Insert(T* values, int size) {
		if (!arr) arr = new T;
		//for (int i = 0; i < size; i++) {
		//	Insert(values[i]);
		//}
		//qty = size;
		qty = size;
		for (int j = 0; j < size; j++) arr[j] = values[j];
		for (int i = 0; i < size; i++) {
			SiftDown(i);
		}
	}

	void SiftDown(int i) {
		while (2 * i + 1 < qty) {
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int j = left;
			if (right < qty && arr[right] < arr[left]) j = right;
			if (arr[i] <= arr[j]) break;
			T buff = arr[i];
			arr[i] = arr[j];
			arr[j] = buff;
			i = j;
		}
	}

	void SiftUp(int i) {
		while (arr[i] < arr[(i - 1) / 2]) {
			T buff = arr[i];
			arr[i] = arr[( i - 1 ) / 2];
			arr[(i-1)/2] = buff;
			i = (i - 1) / 2; // return to parent
		}
	}

	void print() {
		if (!arr) cout << "Empty!" << endl;
		for (int i = 0; i < qty; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}			 

	string ToString() {
		if (!arr) return "Empty!";
		string res = "";
		for (int i = 0; i < qty; i++) {
			res += " " + to_string(arr[i]);
		}
		return res;
	}

	//void traversal
};

