#pragma once

#include <sequence.h>
#include <linkedList.h>

template <class T>
class LinkedListSequence : public Sequence<T>
{
public:
    LinkedListSequence() :
        list(new LinkedList<T>){}

    LinkedListSequence(T* items, int count) :
        list(new LinkedList<T>(items, count)) {}

    LinkedListSequence(const LinkedListSequence<T> & sequence) :
        list(new LinkedList<T>(*sequence.list)) {}

    LinkedListSequence(const LinkedList<T> * list) :
        list(new LinkedList(*list)) {}

    virtual T Get(int index) const override
    {
        return list->Get(index);
    }

    virtual T& operator[](int index) override
    {
        return list->GetRef(index);
    }

    virtual void RemoveAt(int index) override
    {
        list->RemoveAt(index);
    }

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override
    {
        return new LinkedListSequence<T>(list->GetSubList(startIndex, endIndex));
    }

    virtual int GetLength() const override
    {
        return list->GetLength();
    }

    virtual void InsertAt(T item, int index) override
    {
        return list->InsertAt(item, index);
    }

    virtual Sequence<T>* Concat(Sequence<T> * list) const override
    {
        Sequence<T> * copy = new LinkedListSequence(*this);
        for(int i=0; i<list->GetLength(); ++i)
        {
            copy->Append(list->Get(i));
        }
        return copy;
    }

    virtual Sequence<T>* Map(std::function<T(const T &)> f) const override
    {
        Sequence<T>* sequence = new LinkedListSequence<T>;
        for(int i = 0; i < GetLength(); ++i)
        {
            sequence->Append(f(Get(i)));
        }
        return sequence;
    }

    virtual Sequence<T>* Where(std::function<bool(const T &)> f) const override
    {
        Sequence<T>* sequence = new LinkedListSequence<T>;
        for(int i = 0; i < GetLength(); ++i)
        {
            T buf = Get(i);
            if(f(buf))
            {
                sequence->Append(buf);
            }
        }
        return sequence;
    }


    virtual ~LinkedListSequence(){
        delete list;
    }
private:
    LinkedList<T> * list;
};
