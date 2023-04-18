#include <iostream>
#include <string>

using namespace std;

void menu_view (string* data, int count)
{
  cout << "~~~~~~~~~~~~~~~~~" << endl;
  cout << "0. Back" << endl;
  for (int i = 0; i < count; i++)
  {
    cout << i+1 << ". " << data[i] << endl;
  }
  cout << "Enter: ";
  return;
}