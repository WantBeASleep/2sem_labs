#pragma once
#include <iostream>
#include <queue>
#include <string>

using namespace std;
template <class T>
class BinaryHeap
{
  private:
    T* array;
    int size;

  public:

    BinaryHeap()
    {
      array = nullptr;
      size = 0;
    }

    BinaryHeap(T* data, int size_data)
    {
      size = size_data;
      array = new T[size];
      for (int i = 0; i < size; array[i] = data[i], i++);
      for (int i = size/2; i >= 0; Heapify(i), i--);
    }

    void Heapify(int i)
    {
      int leftChild;
      int rightChild;
      int maxChild;
      for ( ; ;)
      {
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
        maxChild = i;

        if (leftChild < size && array[leftChild] > array[maxChild])
        {
          maxChild = leftChild;
        }
        if (rightChild < size && array[rightChild] > array[maxChild])
        {
          maxChild = rightChild;
        }
        if (maxChild == i) break;

        T tmp = array[i];
        array[i] = array[maxChild];
        array[maxChild] = tmp;
        i = maxChild;
      }
    }

    void AddElem(T data)
    {
      T* nArray = new T[size + 1];
      for (int i = 0; i < size; nArray[i] = array[i], i++);
      delete[] array;
      array = nArray;
      size++;

      array[size - 1] = data;
      int i = size - 1;
      int parent = (i-1)/2;

      while (i > 0 && array[parent] < array[i])
      {
        T tmp = array[i];
        array[i] = array[parent];
        array[parent] = tmp;

        i = parent;
        parent = (i-1)/2;
      }
    }

    void Exists(T data)
    {
      for (int i = 0; i < size; i++)
      {
        if (array[i] == data)
        {
          cout << "Exists!" << endl;
          return;
        }
      }
      cout << "No exitst!" << endl;
    }
    
    void Delete(T data)
    {
      int idx_del = -1;
      for (int i = 0; i < size; i++)
      {
        if (array[i] == data) idx_del = i;
      }
      if (idx_del == -1) return;

      T tmp = array[size - 1];
      size--;
      T* nArray = new T[size];
      for (int i = 0; i < size; nArray[i] = array[i], i++);
      delete[] array;
      array = nArray;

      array[idx_del] = tmp;
      Heapify(idx_del);
    }

    void Print() {
      if (size == 0) cout << "Empty!" << endl;
      for (int i = 0; i < size; i++)
      {
        cout << array[i] << " ";
      }
      cout << endl;
	  }

    int GetIndex(T value)
    {
      int idx;
      for (int i = 0; i < size; i++)
      {
        if (array[i] == value) idx = i;
      }
      return idx;
    }

    BinaryHeap<T> GetSubHeap(T data)
    {
      BinaryHeap<T> SubHeap = BinaryHeap<T>();
      queue<int> que;
      int idx = GetIndex(data);
      que.push(array[idx]);

      while (!que.empty())
      {
        idx = GetIndex(que.front());

        SubHeap.AddElem(que.front());
        que.pop();

        if (2 * idx + 1 < size) que.push(array[2 * idx + 1]);
        if (2 * idx + 2 < size) que.push(array[2 * idx + 2]);
      }
      return SubHeap;
    }

    string StrSave()
    {
      string res;
      for (int i = 0; i < size; i++)
      {
        res = res + " " + to_string(array[i]);
      }
      return res;
    }
};