#include <iostream>
#include "Menu.hpp"
#include "BinTree.hpp"
#include "SetTest.hpp"
#include "BinHeap.hpp"

using namespace std;

int main() {
	int flag = 0;
	while (!flag)
	{
		string strings[4] = { "Binary Tree", "Set", "Binary Heap", "Test Binary Heap" };
		Menu menu(4, strings);
		int res = menu.Choice("Main menu");
		switch (res) {
		case 0: {flag = 1; break; }
		case 1: {
			BinTree();
			break;
		}
		case 2: {
			SetTest();
			break;
		}
		case 3: {
			Heap();
			break;
		}
		case 4: {
			HeapTest();
			break;
		}
		case 5: {
			
			break;
		}
		case 6: {
			
			break;
		}


		default: {
			break;
		}
		}
	}

	return 0;
}