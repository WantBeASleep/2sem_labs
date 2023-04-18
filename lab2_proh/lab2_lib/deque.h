#pragma once

#include <sequence.h>
#include <vector>
#include <initializer_list>
#include <arraySequence.h>

template <class T, class S = ArraySequence<T>>
class Deque
{
public:
    Deque() : sequence(new S) {}

    Deque(const Deque<T,S> & copy)
    {
        sequence = new S(*((const S*)copy.sequence));
    }

    void PushBack(T value)
    {
        sequence->Append(value);
    }

    void PushFront(T value)
    {
        sequence->Prepend(value);
    }

    T PopBack()
    {
        T value = sequence->Get(sequence->GetLength()-1);
        sequence->RemoveAt(sequence->GetLength()-1);
        return value;
    }

    T PopFront()
    {
        T value = sequence->Get(0);
        sequence->RemoveAt(0);
        return value;
    }

    int GetSize() const
    {
       return sequence->GetLength();
    }

    Deque<T, S> Map(std::function<T(const T &)> f) const
    {
        return Deque(sequence->Map(f));
    }

    Deque<T, S> Where(std::function<bool(const T &)> f) const
    {
        return Deque(sequence->Where(f));
    }

    T Reduce(std::function<T(const T &, const T &)> f, const T & initial) const
    {
        return sequence->Reduce(f, initial);
    }

    Deque<T, S> Concat(const Deque<T, S> & other) const
    {
        return Deque(sequence->Concat(other.sequence));
    }

    Sequence<T>* GetSubSequence(std::initializer_list<int> indexes) const
    {
        Sequence<T>* result = new S;
        for(int i : indexes)
        {
            result->Append(sequence->Get(i));
        }
        return result;
    }

    Sequence<T>* GetSubSequence(std::vector<int> indexes) const
    {
        Sequence<T>* result = new S;
        for(int i : indexes)
        {
            result->Append(sequence->Get(i));
        }
        return result;
    }


    int FindSubSequence(const Sequence<T> & toFind, int startIndex = 0) const
    {
        if(toFind.GetLength() == 0) {
            return 0;
        }
        int maxIndex = this->sequence->GetLength() - toFind.GetLength();
        for(int i = startIndex; i <= maxIndex; ++i)
        {
            auto* seq = sequence->GetSubsequence(i, i+toFind.GetLength()-1);
            if(*seq == toFind)
            {
                delete seq;
                return i;
            }
            delete seq;
        }
        return -1;
    }

    ~Deque()
    {
        delete sequence;
    }
private:
    Sequence<T> * sequence;

    Deque(Sequence<T> * sequence) : sequence(sequence) {}
};
