#include <iostream>
#include <string>

#include "menu.hpp"
#include "binaryTree.hpp"
#include "sewTree.hpp"

using namespace std;

int map_func(int key);
bool where_func(int key);
int reduce_func(int val1, int val2);

void binary_menu()
{
  cout << endl << "Example AVLtree create." << endl;
  BinaryTree<int> AVL_tree = BinaryTree<int>();
  

  int def_seq[7] = {1, 2, 3, 4, 5, 6, 7};
  for (int i = 0; i < 7; AVL_tree.add_key(def_seq[i]), i++);

  int choise = 1;
  string data[12] = {"Insert", "Delete", "Print KLP", "Print detour", "Map", "Where", "Reduce", "String Save", "Save sub tree", "Check Subtree", "Sew LPK", "default_seq"};
  while (choise)
  {
    menu_view(data, 12);
    cin >> choise;
    switch (choise)
    {
      case 1:
      {
        int key;
        cout << endl << "Enter key: ";
        cin >> key;
        AVL_tree.add_key(key);
        break;
      }
      case 2:
      {
        int key;
        cout << endl << "Enter key: ";
        cin >> key;
        AVL_tree.remove_key(key);
        break;
      }
      case 3:
      {
        AVL_tree.print("KLP");
        break;
      }
      case 4:
      {
        string type_detour;
        cout << "Enter the type(KPL,LKP...): ";
        cin >> type_detour;
        AVL_tree.print(type_detour);
        break;
      }
      case 5:
      {
        BinaryTree<int>* map_tree = AVL_tree.map(map_func);
        map_tree->print("KLP");
        delete map_tree;
        break;
      }
      case 6:
      {
        BinaryTree<int>* where_tree = AVL_tree.where(where_func);
        where_tree->print("KLP"); 
        delete where_tree;
        break;
      }
      case 7:
      {
        cout << "Reduce(tree): " << AVL_tree.reduce(reduce_func, 0) << endl;
        break;
      }
      case 8:
      {
        string type_detour;
        cout << "Enter the type(KPL,LKP...): ";
        cin >> type_detour;
        string str = AVL_tree.string_save(type_detour);
        cout << "Str content: " << str << endl;
        break;
      }
      case 9:
      {
        int key;
        cout << endl << "Enter key: ";
        cin >> key;
        BinaryTree<int>* subtree = AVL_tree.get_subtree(key);

        subtree->print("KLP");
        delete subtree;
        break;
      }
      case 10:
      {
        BinaryTree<int>* sub_tree = new BinaryTree<int>();
        
        int subtree_seq[7] = {1, 2, 3, 4, 5, 6, 7};
        for (int i = 0; i < 7; sub_tree->add_key(subtree_seq[i]), i++);
        bool res = AVL_tree.check_subtree(sub_tree);
        cout << "Res: " << res << endl;
        break;
      }
      case 11:
      {
        sewTree<int> sew_tree = sewTree<int>(&AVL_tree);
        sew_tree.sew_base();
        sew_tree.print_base();
        break;
      }
      case 12:
      {
        int def_seq[7] = {1, 2, 3, 4, 5, 6, 7};
        for (int i = 0; i < 7; AVL_tree.add_key(def_seq[i]), i++);
        break;
      }
    }
  }
}

int map_func(int key)
{
  return 10 * key;
}

bool where_func(int key)
{
  if (key > 5) return false;
  return true;
}

int reduce_func(int val1, int val2)
{
  return val1 + val2;
}