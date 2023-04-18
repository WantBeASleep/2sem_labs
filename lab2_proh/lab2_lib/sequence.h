#pragma once

#include <functional>
#include <iostream>

template <class T>
class Sequence
{
public:
    bool friend operator==(const Sequence<T> & a, const Sequence<T> & b)
    {
        if(a.GetLength() != b.GetLength())
        {
            return false;
        }

        for(int i = 0; i < a.GetLength(); ++i)
        {
            if(a.Get(i) != b.Get(i))
            {
                return false;
            }
        }
        return true;
    }

    friend std::ostream & operator<<(std::ostream & s, const Sequence<T> & seq)
    {
        s << "{";
        if(seq.GetLength() > 0)
        {
            s << seq[0];
            for(int i = 1; i < seq.GetLength(); ++i)
            {
                s << ", " << seq[i];
            }
        }
        s << "}";
        return s;
    }

    T operator[](int index) const
    {
        return Get(index);
    }

    virtual T& operator[](int index) = 0;
    virtual T Get(int index) const = 0;
    virtual void Set(int index, T value)
    {
        (*this)[index] = value;
    }

    T GetFirst() const
    {
        Get(0);
    }

    T GetLast() const
    {
        Get(GetLength()-1);
    }

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;

    virtual int GetLength() const = 0;

    void Append(T item)
    {
        InsertAt(item, GetLength());
    }

    void Prepend(T item)
    {
        InsertAt(item, 0);
    }

    virtual void InsertAt(T item, int index) = 0;
    virtual void RemoveAt(int index) = 0;

    virtual Sequence<T>* Concat(Sequence<T> * list) const = 0;

    virtual Sequence<T>* Map(std::function<T(const T &)> f) const = 0;

    virtual Sequence<T>* Where(std::function<bool(const T &)> f) const = 0;

    T Reduce(
        std::function<T(const T & val, const T & acc)> f,
        const T & initial)
    {
        T val = initial;
        for(int i = 0; i < GetLength(); ++i)
        {
            val = f(Get(i), val);
        }
        return val;
    }

    virtual ~Sequence<T>() {}
};
