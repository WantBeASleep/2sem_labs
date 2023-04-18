#pragma once

#include <iostream>

using namespace std;

template<class T>
class Item{
public:
  T data;
  Item<T>* next;
  Item<T>* prev;
};

template <class T>
class LinkedList{
private:
  Item<T>* head;
  Item<T>* tail;
  int length;

public:
  //Create empty list
  LinkedList()
  {
    head = NULL;
    tail = NULL;
    length = 0;
  }
  // Copying constructor
  LinkedList(T* items, int count)
  {
    head = NULL;
    tail = NULL;
    length = 0;
    for (int i = 0; i < count; Append(items[i]), i++);
  }

  LinkedList(const LinkedList<T>& list)
  {
    head = NULL;
    tail = NULL;
    length = 0;
    for (int i = 0; i < list.length; Append(list.Get(i)), i++);
  }

  // OPERATOR
/*
  Item<T>* operator[](int index)
  {
    if (!length) return NULL;
    Item<T>* buff = head;
    for (int i = 0; i < index; buff = buff->next, i++);
    return buff;
  }
*/
  //Decomposing
  T GetFirst()
  {
    return head->data;
  }

  T GetLast()
  {
    return tail->data;
  }

  T Get(int index)
  {
    Item<T>* buff = head;
    for (int i = 0; i < index; buff = buff->next, i++);
    return buff->data;
  }

  LinkedList<T>* GetSubList(int startIndex, int endIndex)
  {
    LinkedList<T>* buff = new LinkedList<T>();
    for (int i = startIndex; i < endIndex; buff->Append(Get(i)), i++);
    return buff;
  }

  int GetLength()
  {
    return length;
  }

  void Set(int index, T data)
  {
    Item<T> *buff = head;
    for (int i = 0; i < index; buff = buff->next, i++);
    buff->data = data;
  }

  void Append(T item)
  {
    Item<T>* buff = new Item<T>;
    buff->next = NULL;
    buff->data = item;
    if (head == NULL){
      head = buff;
      head->prev = NULL;
      tail = head;
    }
    else{
      tail->next = buff;
      buff->prev = tail;
      tail = buff;
    }
    length++;
  }

  void Prepend(T item){
    length++;
    Item<T>* buff = new Item<T>;
    buff->next = NULL;
    buff->data = item;

    if(head == NULL){
      head = buff;
      head->prev = NULL;
      tail = head;
    }
    else{
      head->prev = buff;
      buff->next = head;
      head  = buff;
    }  
  }

  void InsertAt(T item, int index){
    Item<T>* oldItem = head;
    for (int i = 0; i < index; oldItem = oldItem->next, i++);

    if (length == 0){
      Append(item);
    } else{
      Item <T>* buff = new Item<T>;
      buff->data = item;
      buff->prev = oldItem->prev;
      buff->next = oldItem;
      oldItem->prev->next = buff;
      oldItem->prev = buff;
      length++;
    }
  }

  LinkedList<T>* Concat(LinkedList<T>* list){
      for (int i = 0; i < list->length; i++) {
          Append(list->Get(i));
      }
      return this;
  }

  void print() 
  {
    cout << "Length: " << length << endl;
    cout << "[ ";
    Item<T>* buff = head;
    for (int i = 0; i < length; i++) {
      cout << buff->data << " ";
      buff = buff->next;
    }

    cout << "]" << endl;
  }

};