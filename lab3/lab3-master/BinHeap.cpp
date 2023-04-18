#include <iostream>
#include "BinaryHeap.hpp"
#include "Menu.hpp"
#include <cstring>

void HeapTest() {
	cout << "Insertion {1000, 7, 3, 4 , 500, 9, 99}" << endl;
	int arr[7] = { 1000, 7, 3, 4, 500, 9, 99 };
	int size = 7;
	auto heap = new BinaryHeap<int>(arr, size);

	heap->print();



	cout << endl << "Insertion 13, 3, 0" << endl;
	heap->Insert(13);
	heap->Insert(3);
	heap->Insert(0);
	heap->print();

	cout<< endl << "ToString:";
	cout << endl << heap->ToString() << endl;
}

void Heap() {
	cout << "Creating empty tree" << endl;
	int flag = 0;
	auto heap = new BinaryHeap<int>();
	while (!flag) {
		string strings[4] = { "Print", "Insert 1 element", "Insert elements", "To String" };
		Menu menu(3, strings);
		int res = menu.Choice("Main menu");
		switch (res){
		case 0: {flag = 1; break; }
		case 1: {
			heap->print();
			break;
			}
		case 2: {
			int elem = 0;
			cout << "Enter element: ";
			cin >> elem;
			heap->Insert(elem);
			break;
		}
		case 3: {
			cout << "Enter quantity of elements: ";
			int qty = 0;
			cin >> qty;
			int* arr = new int[qty];
			for (int i = 0; i < qty; i++) {
				cout << "[" << i << "]: ";
				cin >> arr[i];
			}
			heap->Insert(arr, qty);
			break;
		}
		case 4: {
			break;
		}
		default: {
			break;
		}
		}
	}
}