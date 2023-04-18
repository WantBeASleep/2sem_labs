#include <iostream>
#include "Set.hpp"
#include <cstring>

void SetTest() {
	cout << "Insertion {1, 2, 3, 4 , 5, 9, 10}" << endl;
	int arr[7] = { 1,2,3,4,5,9,10 };
	int size = 7;
	Set<int>* set = new Set<int>();
	set->Insert(arr, size);
	cout << "Result: "; set->Print();

	cout << "Find 5: " << endl;
	if (set->Find(5) == 1) cout <<"Found!"<< endl;

	cout << "Delete 10: " << endl;
	set->Delete(10);
	cout << "Result: "; 
	set->Print();
	cout << endl;

	cout << "Map (*scalar = 100): " << endl;
	set->Map(100);
	cout << "Result: "; set->Print();
	cout << endl;

	cout << "Reduce: ";
	int res = set->Reduce();
	cout << "Result: " << res << endl << endl;

	//Where()
	
	cout << "Union {100, 200, 300, 400 , 500, 900} with {1, 3, 100}" << endl;
	int arr1[3] = {1, 3, 100};
	int size1 = 3;
	Set<int>* set1 = new Set<int>();
	set1->Insert(arr1, size1);
	set->Unif(set1);
	cout << "Result: " << endl;
	set->Print();
	cout << endl;

	cout << "{1, 3, 100, 200, 300, 400 , 500, 900} Minus {1, 900}" << endl;
	int arr2[2] = { 1, 900 };
	int size2 = 2;
	Set<int>* set2 = new Set<int>();
	set2->Insert(arr2, size2);
	set->Minus(set2);
	cout << "Result: " << endl;
	set->Print();
	cout << endl;

	cout << "Intersection {3, 100, 200, 300, 400 , 500} with {1, 3, 200}" << endl;
	int arr3[3] = { 1, 3, 200};
	int size3 = 3;
	Set<int>* set3 = new Set<int>();
	set3->Insert(arr3, size3);
	set = set->Intersection(set3);
	cout << "Result: " << endl;
	set->Print();
	cout << endl;

	cout << "Is {3, 200} equals to {1, 3, 200} ?" << endl;
	int arr4[3] = { 1, 3, 200 };
	int size4 = 3;
	Set<int>* set4 = new Set<int>();
	set4->Insert(arr4, size4);
	int answer = set->Equals(set4);
	if (answer == 0) cout << "Result: No" << endl;
	cout << endl;

	cout << "Is {3, 200} a subsequence of {3, 200, 300}?" << endl;
	int arr5[3] = {3, 200, 300};
	int size5 = 3;
	Set<int>* set5 = new Set<int>();
	set5->Insert(arr5, size5);
	set5 = set5->Intersection(set);
	set5->Print();
	int answer1 = set->Equals(set5);
	if (answer1 == 1) cout << "Result: Yes" << endl;
	cout << endl;



}