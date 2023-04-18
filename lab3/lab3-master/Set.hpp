#pragma once
#include <iostream>
#include "BinaryTree.hpp"
#include <cstring>

using namespace std;

template <class T>
class Set {
private:
	BinaryTree<T>* data;
public:
	Set() {
		data = new BinaryTree<T>();
	}

	void Insert(T elem) {
		data->Insert(elem);
	}

	void Insert(T* elems, int size) {
		for (int i = 0; i < size; i++) {
			data->Insert(elems[i]);
		}
	}

	int Find(T elem) {
		return data->Find(elem);
	}

	void Delete(T elem) {
		data->Delete(elem);
	}

	void Map(int scalar) {
		data->Map(scalar);
	}

	T Reduce() {
		return data->Reduce();
	}

	//Set* Where();

	void Unif(Set<T>* set) {
		T* array = set->data->ToArray();
		for (int i = 0; i < set->data->GetSize(); i++) {
			Insert(array[i]);
		}
	}

	Set<T>* Intersection(Set<T>* set) {
		T* arr1 = this->data->ToArray();
		T* arr2 = set->data->ToArray();
		Set<T>* result = new Set<T>();

		for (int i = 0; i < data->GetSize(); i++) {
			for (int j = 0; j < set->data->GetSize(); j++) {
				if (this->Find(arr2[j]) == 1 && set->Find(arr1[i]) == 1) {
					result->Insert(arr2[j]);
				}
			}
		}
		return result;
	}

	void Minus(Set<T>* set) {
		T* array = set->data->ToArray();
		for (int i = 0; i < set->data->GetSize(); i++) {
			Delete(array[i]);
		}
	}

	int Equals(Set<T>* set) {
		int result = 1;
		T* arr1 = this->data->ToArray();
		T* arr2 = set->data->ToArray();

		for (int i = 0; i < data->GetSize(); i++) {
			for (int j = 0; j < set->data->GetSize(); j++) {
				if (!(this->Find(arr2[j]) == 1 && set->Find(arr1[i]) == 1)) {
					result = 0;
				}
			}
		}
		return result;
	}

	void Print() {
		data->Print();
	}

	int operator == (Set<T>* set) {
		if (this->Equals(set)) return 1;
		else return 0;
	}
	Set<T>* operator + (Set<T>* set) {
		return this->Unif(set);
	}

	string ToString() {
		return data->ToString();
	}
};
