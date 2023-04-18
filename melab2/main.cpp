#include <iostream>
#include <string>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "DynamicArray.hpp"

#include "firstTask.hpp"
#include "secondTask.hpp"

using namespace std;

int main()
{
  cout << "1. firstTask\n2. secondTask\n";
  int task = 0;
  cin >> task;
  switch(task)
  {
    case 1:
      firstTask();
      break;
    case 2:
      secondTask();
      break;
  }
  return 0;
}