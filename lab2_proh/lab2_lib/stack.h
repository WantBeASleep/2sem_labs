#pragma once

#include <deque.h>

template <class T, class S>
class Stack
{
public:
    Stack(Sequence<T> * seq)
        : deque(Deque(seq)) {}

    void Push(T value)
    {
        deque.PushBack(value);
    }

    T Pop()
    {
        return deque.PopBack();
    }

    Stack<T, S> Map(std::function<T(const T &)> f) const
    {
        return Stack(deque.map(f));
    }

    Stack<T, S> Where(std::function<bool(const T &)> f) const
    {
        return Stack(deque.Where(f));
    }

    T Reduce(
            std::function<T(const T &, const T &)> f,
            const T & initial) const
    {
        return Stack(deque.Reduce(f, initial));
    }

    Stack<T, S> Concat(const Stack<T, S> & other) const
    {
        return Stack(deque.Concat(other.deque));
    }

    Sequence<T> * GetSubSequence(std::initializer_list<int> indexes) const
    {
        return deque.GetSubSequence(indexes);
    }

    Sequence<T> * GetSubSequence(std::vector<int> indexes) const
    {
        return deque.GetSubSequence(indexes);
    }

    int FindSubSequence(const Sequence<T> & sub, int startIndex = 0) const
    {
        return deque.FindSubSequence(sub, startIndex);
    }
private:
    Deque<T, S> deque;

    Stack(Deque<T, S> deque)
        : deque(deque) {}
};
