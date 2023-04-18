#include <iostream>
#include "Menu.hpp"

using namespace std;

int main()
{
  int choise = 1;
  while (choise)
  {
    string choises[3] = {"Binary Tree", "Binary Tree Test", "Binary Heap"};
    menu(choises, 3);
    cin >> choise;
    switch (choise)
    {
      case 0:
      {
        break;
      }
      case 1:
      {
        BinaryTreeMenu();
        break;
      }
      case 2:
      {
        TreeTest();
        break;
      }
      case 3:
      {
        BinaryHeapMenu();
        break;
      }
    }
  }
  return 0;
}