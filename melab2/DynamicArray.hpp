#pragma once

#include <iostream>

using namespace std;

template<class T>
class DynamicArray
{
  private:
    T* data;
    int length;
  
  public:
    DynamicArray(T* origArray, int size)
    {
      data = new T[size];
      length = size;
      for(int i = 0; i < length; i++)
      {
        data[i] = origArray[i];
      }
    }

    DynamicArray(int size)
    {
      data = new T[size];
      length = size;
      for(int i = 0; i<length; data[i] = 0, i++);
    }
    
    DynamicArray(const DynamicArray<T>& array)
    {
      data = new T[array.length];
      length = array.length;
      for(int i = 0; i < array.length; data[i] = array.data[i], i++){}
    }
    
    T Get(int index)
    {
      return data[index];
    }
    
    int GetSize()
    {
      return length;
    }
  
    void Set(int index, T value)
    {
      data[index] = value;
    }
    
    void Resize(int newSize)
    {
      T* newData = new T[newSize];
      for (int i = 0; i < newSize; i++)
      {
        if (i < length)
        {
          newData[i] = data[i];
        } else {
          newData[i] = 0;
        }
      }
      delete data;
      data = newData;
      length = newSize;
    }

    void Print()
    {
      cout << "{";
      for (int i = 0; i < length; i++)
      {
        cout << data[i];
        if (i != length-1) cout << ", ";
      }
      cout << "}" << endl;
    }
};