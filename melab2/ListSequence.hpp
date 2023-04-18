#pragma once

#include <iostream>
#include "Sequence.hpp"
#include "LinkedList.hpp"

template <class T>
class ListSequence : public Sequence<T>
{
  private:
    LinkedList<T>* data;
  public:
    ListSequence(ListSequence<T>& list)
    {
      data = new LinkedList<T>;
      for (int i = 0; i < list.GetLength(); i++) {
        this->Append(list.Get(i));
      }
    }

    ListSequence()
    {
      data = new LinkedList<T>;
    }

    ListSequence(T* items, int count)
    {
      data = new LinkedList<T>(items, count);
    }

    void SetSequence(int size) override
    {
      for (int i = 0; i < size; i++)
      {
        int elem;
        cout << "data[" << i << "]: ";
        cin >> elem;
        data->Append(elem);
      }
    }

    void GetExSequence(int size, T* example)
    {
      for (int i = 0; i < size; data->Append(example[i]), i++);
    }

    void Resize(int newSize)
    {
      if (newSize > data->GetLength())
      {
        for (int i = data->GetLength(); i < newSize; data->Append(0), i++);
      }
    }

    T GetFirst() override
    {
      return data->GetFirst();
    }

    T GetLast() override
    {
      return data->GetLast();
    }

    T Get(int index) override
    {
      return data->Get(index);
    }
    Item<T>* operator[](int const index)
    {
      return (data->operator[](index));
    }
    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
      ListSequence<T>* res = new ListSequence<T>;
      for (int i = startIndex; i < endIndex; res->Append(data->Get(i)), i++);
      return res;
      /* 
      LinkedList<T>* buffList = new LinkedList<T>(*(data->GetSubList(startIndex, endIndex)));
      ListSequence<T>* buffListSeq = new ListSequence<T>;
      for (int i = 0; i < buffList->GetLength(); i++) {
          buffListSeq->Append(buffList->Get(i));
      }
      delete buffList;
      return (ListSequence<T>*)buffListSeq;
      */
    }
    
    int GetLength() override
    {
      return data->GetLength();
    }
    
    void Set(int index, T item)
    {
      data->Set(index, item);
    }
    
    void Append(T item) override
    {
      data->Append(item);
    }

    void Prepend(T item) override
    {
      data->Prepend(item);
    }

    void InsertAt(T item, int index) override
    {
      data->InsertAt(item, index);
    }

    void Print() override
    {
      data->print();
    }

    ListSequence<T>* Concat (Sequence<T>* list) override
    {
      for (int i = 0; i < list->GetLength(); i++) {
        data->Append(list->Get(i));
      }
      return this;
    }

};