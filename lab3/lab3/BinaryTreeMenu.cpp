#include <iostream>
#include <string>
#include "BinaryTree.hpp"
#include "Menu.hpp"

using namespace std;

int MapFunc(int value);
bool WhereFunc(int value);
int ReduceFunc(int val1, int val2);

void BinaryTreeMenu()
{
  cout << "Empty tree create." << endl;
  BinaryTree<int> tree = BinaryTree<int>();
  int choise = 1;
  while (choise)
  {
    string choises[12] = {"Print", "Add element", "Delete element", "Example tree", "Map", "Where", "Reduce", "Merge", "Get Subtree", "String_base", "String_choose", "Check_Subtree"};
    menu(choises, 12);
    cin >> choise;
    switch (choise)
    {
      case 0:
      {
        break;
      }
      case 1:
      {
        tree.Print();
        break;
      }
      case 2:
      {
        cout << "Elem add?: ";
        int elem;
        cin >> elem;
        tree.AddElem(elem);
        break;
      }
      case 3:
      {
        cout << "Elem Dell?: ";
        int elem;
        cin >> elem;
        tree.DeleteElem(elem);
        break;
      }
      case 4:
      {
        int arr[8] = {66, 91, 7, 64, 78, 5, 9, 93};
        for (int i = 0; i < 8; tree.AddElem(arr[i]), i++);
        tree.Print();
        break;
      }
      case 5:
      {
        tree.Map(MapFunc);
        break;
      }
      case 6:
      {
        tree.Where(WhereFunc);
        break;
      }
      case 7:
      {
        cout << "Reduce(tree) = " << tree.Reduce(ReduceFunc, 0) << endl;
        break;
      }
      case 8:
      {
        BinaryTree<int> tree2 = BinaryTree<int>();
        cout << "New tree size?: ";
        int size, elem;
        cin >> size;
        for(int i = 0; i < size; i++)
        {
          cout << "Elem[" << i << "]: ";
          cin >> elem;
          tree2.AddElem(elem);
        }
        tree.Merge(tree2);
        break;
      }
      case 9:
      {
        cout << "Root of new sbtr?: ";
        int root;
        cin >> root;

        tree.GetSubTree(root);
        break;
      }
      case 10:
      {
        //sting_base
        string str_base = tree.StringSaveBase();
        cout << str_base << endl;
        break;
      }
      case 11:
      {
        //string_choose
        cout << "0 - K\n1 - L\n2 - P\nExample: 012(KLP): ";
        int seq[3];
        for(int i = 0;  i < 3; i++)
        {
          cin >> seq[i];
        }
        string str_choose = tree.StringSaveChoose(seq);
        cout << str_choose << endl;
        break;
      }
      case 12:
      {
        BinaryTree<int> tree3 = BinaryTree<int>();
        cout << "New tree size?: ";
        int size, elem;
        cin >> size;
        for(int i = 0; i < size; i++)
        {
          cout << "Elem[" << i << "]: ";
          cin >> elem;
          tree3.AddElem(elem);
        }
        bool res = tree.Check_SubTree(tree3);
        cout << "Res: " << res << endl;
        break;
      }
    }
  }
}

int MapFunc(int value)
{
  return 10 * value;
}

bool WhereFunc(int value)
{
  int base = 50;
  if (value > base) return false;
  else return true;
}

int ReduceFunc(int val1, int val2)
{
  return val1 + val2;
}