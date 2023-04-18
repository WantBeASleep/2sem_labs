#pragma once

#include <sequence.h>
#include <dynamicarray.h>

template <class T>
class ArraySequence : public Sequence<T>
{
public:
    ArraySequence() :
        array(new DynamicArray<T>(0)) {}

    ArraySequence(int count) :
        array(new DynamicArray<T>(count)) {}

    ArraySequence(T* items, int count) :
        array(new DynamicArray(items, count)) {}

    ArraySequence(const ArraySequence<T> & sequence) :
        array(new DynamicArray<T>(*sequence.array)) {}

    virtual T Get(int index) const override
    {
        return array->Get(index);
    }

    virtual T& operator[](int index) override
    {
        return (*array)[index];
    }

    virtual Sequence<T> * GetSubsequence(int startIndex, int endIndex) const override
    {
        DynamicArray<T> * subArray = new DynamicArray<T>(endIndex - startIndex + 1);
        for(int i = startIndex; i <= endIndex; ++i)
        {
            subArray->Set(i - startIndex, Get(i));
        }
        return new ArraySequence<T>(subArray);
    }

    virtual int GetLength() const override
    {
        return array->GetSize();
    }

    virtual void InsertAt(T item, int index) override
    {
        array->Resize(array->GetSize()+1);
        for(int i = index; i < array->GetSize()-1; ++i)
        {
            (*array)[i+1] = (*array)[i];
        }
        (*array)[index] = item;
    }

    virtual void RemoveAt(int index) override {
        for(int i = index+1; i < GetLength(); ++i)
        {
            (*array)[i-1] = (*array)[i];
        }
        array->Resize(array->GetSize()-1);
    }

    virtual Sequence<T>* Concat(Sequence<T> * sequence) const override
    {
        ArraySequence<T>* newSequence = new ArraySequence<T>(*this);
        for(int i = 0; i < sequence->GetLength(); ++i)
        {
            newSequence->Append(sequence->Get(i));
        }
        return newSequence;
    }

    virtual Sequence<T>* Map(std::function<T(const T &)> f) const override
    {
        Sequence<T>* sequence = new ArraySequence<T>;
        for(int i = 0; i < GetLength(); ++i)
        {
            sequence->Append(f(Get(i)));
        }
        return sequence;
    }

    virtual Sequence<T> * Where(std::function<bool(const T &)> f) const override
    {
        Sequence<T> * sequence = new ArraySequence<T>;
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

    virtual ~ArraySequence()
    {
        delete array;
    }

private:
    DynamicArray<T> * array;

    ArraySequence(DynamicArray<T> * array) :
        array(array) {}
};
