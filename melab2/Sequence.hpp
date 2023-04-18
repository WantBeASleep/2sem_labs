#pragma once

template <class T>
class Sequence
{
  private:
  public:
  // Задание
    virtual void SetSequence(int size) = 0;
    virtual void Set(int index, T item) = 0;
    virtual void GetExSequence(int size, T* example) = 0;
  // Изменения
    virtual void Resize(int newSize) = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
  //Декомпозиция
    virtual T Get(int index) = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual int GetLength() = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual void Print() = 0;
  //Операции
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
};