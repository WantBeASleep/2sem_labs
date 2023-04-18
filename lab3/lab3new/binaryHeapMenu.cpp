#include <iostream>
#include <string>
#include "binaryHeap.hpp"
#include "menu.hpp"

using namespace std;


void heap_menu()
{
  cout << "Empty Heap create." << endl;
  BinaryHeap<int> heap = BinaryHeap<int>();
  int choise = 1;
  while (choise)
  {
    string choises[6] = {"Print", "Add element", "Delete element", "Example heap", "SubHeap", "Save_toStr"};
    menu_view(choises, 6);
    cin >> choise;
    switch (choise)
    {
      case 0:
      {
        break;
      }
      case 1:
      {
        heap.Print();
        break;
      }
      case 2:
      {
        cout << "Elem: ";
        int elem;
        cin >> elem;
        heap.AddElem(elem);
        break;
      }
      case 3:
      {
        cout << "Elem: ";
        int elem;
        cin >> elem;
        heap.Delete(elem);
        break;
      }
      case 4:
      {
        int example[10] = {8, 15, 11, 6, 9, 7, 8, 1, 3, 5};
        int size = 10;
        heap = BinaryHeap<int>(example, size);
        break;
      }
      case 5:
      {
        cout << "Elem: ";
        int elem;
        cin >> elem;
        BinaryHeap<int> subheap = heap.GetSubHeap(elem);
        subheap.Print();
        break;
      }
      case 6:
      {
        string res = heap.StrSave();
        cout << res << endl;
        break;
      }
    }
  }
}