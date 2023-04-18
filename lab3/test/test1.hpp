#pragma once

#include <iostream>

using namespace std;

template <class T>
class test1
{
  public:
    void foo()
    {
      cout << "1" << endl;
    }
};

template <class T>
class test2 : public test1<T>
{
  public:
  void bar()
  {
    test1<T>::foo();
  }
};