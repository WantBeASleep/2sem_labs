#include <iostream>
#include <string>

#include "menu.hpp"
#include "binaryTreeMenu.hpp"
#include "binaryHeapMenu.hpp"

using namespace std;

int main()
{
  int choise = 1;
  string data[2] = {"Binary Tree", "Heap"};
  while (choise)
  {
    menu_view(data, 2);
    cin >> choise;

    switch (choise)
    {
      case 1:
      {
        binary_menu();
        break;
      }
      case 2:
      {
        heap_menu();
        break;
      }
    }
  }
  return 0;
}