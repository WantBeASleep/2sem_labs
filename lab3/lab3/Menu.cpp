#include <iostream>

using namespace std;

void menu(string* choises, int count)
{
  cout << "~~~~~~~~~~~~~~~~~~~"  << endl;
  for (int i = 0; i < count; i++)
  {
    cout << i+1 << ". " << choises[i] << endl;
  }
  cout << "0. Back\nEnter?: ";
  return;
}