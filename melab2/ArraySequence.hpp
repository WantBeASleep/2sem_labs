#pragma once

#include <iostream>
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template<class T>
class ArraySequence : public Sequence<T>
{
  private:
    DynamicArray<T>* data;
  public:
//default
  // Создание
    ArraySequence()
    {
      data = new DynamicArray<T>(0);
    }

    ArraySequence(int n)
    {
      data = new DynamicArray<T>(n);
    }

    ArraySequence(T* items, int count)
    {
      data = new DynamicArray<T>(items, count);
    }

    ArraySequence(const DynamicArray<T>& array)
    {
      data = new DynamicArray<T>(array);
    }
  // Декомпозиция
    T Get(int index) override
    {
      return data->Get(index);
    }

    T GetFirst() override
    {
      return this->Get(0);
    }

    T GetLast() override
    {
      return this->Get(data->GetSize() - 1);
    }

    int GetLength() override
    {
      return data->GetSize();
    }    

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
      ArraySequence<T>* res = new ArraySequence<T>;
      res->Resize(endIndex - startIndex);
      int j = 0;
      for (int i = startIndex; i < endIndex; i++)
      {
        res->Set(j, data->Get(i));
        j++;
      }
      return res;
    }
    ArraySequence<T>* Concat(Sequence<T>* secSeq) override
    {
      ArraySequence<T>* buff = new ArraySequence<T>;
      /*
      int oldSize = data->GetSize();
      int j = 0;
      data->Resize(data->GetSize() + secSeq->GetLength());
      for (int i = oldSize; i < data->GetSize(); i++)
      {
        data->Set(i, secSeq->Get(j));
        j++;
      }
      */
      return buff;
    }
    void SetSequence(int size) override
    {
      data->Resize(size);
      for(int i = 0; i < size; i++)
      {
        T value;
        cout << "data[" << i << "]: ";
        cin >> value;
        data->Set(i, value);
      }
    }
  
    void Set(int index, T value) override
    {
      data->Set(index, value);
    }

    void GetExSequence(int size, T* example) override
    {
      data->Resize(size);
      for (int i=0; i < size; data->Set(i, example[i]), i++);
    }

    void Resize(int newSize) override
    {
      data->Resize(newSize);
    }

    void Append(T item) override
    {
      data->Resize(data->GetSize() + 1);
      data->Set(data->GetSize()-1, item);
    }

    void Prepend(T item) override
    {
      data->Resize(data->GetSize() + 1);
      for (int i = data->GetSize() - 1; i > 0; data->Set(i, data->Get(i-1)), i--);
      data->Set(0, item);
    }

    void InsertAt(T item, int index) override
    {
      data->Resize(data->GetSize() + 1);
      for (int i = data->GetSize() - 1; i > index; data->Set(i, data->Get(i-1)), i--);
      data->Set(index, item);
    }

    void Print() override
    {
      data->Print();
    }
};