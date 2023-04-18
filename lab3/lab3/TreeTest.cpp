#include <iostream>
#include "BinaryTree.hpp"

int MapFuncTest(int value);
bool WhereFuncTest(int value);
int ReduceFuncTest(int val1, int val2);

void TreeTest()
{
  BinaryTree<int> testTree = BinaryTree<int>();
  cout << "Example Tree" << endl;
  cout << "Example tree data: {66, 91, 7, 64, 78, 5, 9, 93}" << endl;
  int arr[8] = {66, 91, 7, 64, 78, 5, 9, 93};
  for (int i = 0; i < 8; testTree.AddElem(arr[i]), i++);

  cout << "Ways tree:" << endl;
  testTree.Print();

  cout << "Add Elems {1, 8, 10, 95, 97}" << endl;
  int arr2[5] = {1, 8, 10, 95, 97};
  for (int i = 0; i < 5; testTree.AddElem(arr2[i]), i++);
  testTree.Print();

  cout << "Delete Elems: {97, 66}" << endl;
  testTree.DeleteElem(97);
  testTree.DeleteElem(66);
  testTree.Print();

  cout << "Map func: f(x) = 10 * x, func(tree): " << endl;
  testTree.Map(MapFuncTest);
  testTree.Print();

  cout << "Where func: f(x) = true (x < 500), else false, func(tree): " << endl;
  testTree.Where(WhereFuncTest);
  testTree.Print();

  cout << "Reduce func: f(x1, x2) = x1 + x2, func(tree): " << endl;
  cout << "Reduce(tree) = " << testTree.Reduce(ReduceFuncTest, 0) << endl;

  cout << "Sub tree find of Root (7)" << endl;
  testTree.GetSubTree(7);
}

int MapFuncTest(int value)
{
  return 10 * value;
}

bool WhereFuncTest(int value)
{
  int base = 500;
  if (value > base) return false;
  else return true;
}

int ReduceFuncTest(int val1, int val2)
{
  return val1 + val2;
}
