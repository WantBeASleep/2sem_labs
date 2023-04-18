#include <iostream>
#include "BinaryTree.hpp"
#include "Menu.hpp"
using namespace std;

void BinTree() {
	cout << "Creating empty tree" << endl;
	BinaryTree<int> tree = BinaryTree<int>();
	int flag = 0;
	while (!flag)
	{
		string strings[12] = { "Print","Insert element", "Find element", "Delete element", "Map", "Where", "Reduce", "Merge", "Example Tree", "Sub Tree Find", "ToString", "Insert from Massive"};
		for (int i = 0; i < 12; cout << i+1 << ". " << strings[i] << endl, i++);
		cout << "Enter number || Press 0 to Exit : ";
		int res;
		cin >> res;
		//Menu menu(9, strings);
		//int res = menu.Choice("Main menu");
		switch (res) {
		case 0: {flag = 1; break; }
		case 1: {
			tree.Print();
			break;
		}
		case 2: {
			cout << "Enter element: ";
			int newelem = 0;
			cin >> newelem;
			tree.Insert(newelem);
			break;
		}

		case 3: {
			cout << "Enter element: ";
			int elem = 0;
			cin >> elem;
			int result = tree.Find(elem);
			if (result) cout << "Found!" << endl;
			else  cout << " Not found!" << endl;
			break;
		}
		case 4: {
			cout << "Enter element: ";
			int newelem = 0;
			cin >> newelem;
			tree.Delete(newelem);
			break;
		}
		case 5: {
			cout << "Enter scalar: ";
			int scalar = 0;
			cin >> scalar;
			tree.Map(scalar);
			break;
		}
		case 6: {
			int condition;
			cout << "Less than: ";
			cin >> condition;
			tree.Where(condition);
			break;
		}

		case 7: {
			int sum = tree.Reduce();
			cout << "Result: " << sum << endl;
			break;
		}
		case 8: {
			BinaryTree<int> tree2 = BinaryTree<int>();
			tree2.ExTree(10);
			tree.Merge(&tree2);
			break;
		}
		case 9: {
			int count;
			cout << "Count: ";
			cin >> count;
			tree.ExTree(count);
			break;
		}
		case 10: {
			BinaryTree<int> tree2 = BinaryTree<int>();
			tree2.ExTree(3);
			tree.SubTreeEntry(&tree2);
			break;
		}
		case 11: {
			cout << tree.ToString() << endl; 
			break;
		}
		case 12: {
			int lenght;
			cout << "Massive lenght: ";
			cin >> lenght;
			int *arr = new int[lenght];
			for (int i = 0; i < lenght; cout << "arr[" << i << "]: ", cin >> arr[i], i++);
			tree.InsertFromMassive(arr, lenght);
			break;
		}
		case 13: {
			BinaryTree<int> tree2 = BinaryTree<int>(tree);
			tree2.Print();
			break;
		}

		default: {

			break;
		}
		}
	}
}