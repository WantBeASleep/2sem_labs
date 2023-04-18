#pragma once

#include <deque.h>

template <class T, class S>
class Queue
{
public:
    Queue() {}

    Queue(const Queue<T,S> & copy) : deque(copy.deque)
    {}

    void Push(T value)
    {
        deque.PushBack(value);
    }

    T Pop()
    {
        return deque.PopFront();
    }

    Queue<T, S> Map(std::function<T(const T &)> f) const
    {
        return Queue(deque.map(f));
    }

    Queue<T, S> Where(std::function<bool(const T &)> f) const
    {
        return Queue(deque.Where(f));
    }

    T Reduce(
            std::function<T(const T &, const T &)> f,
            const T & initial) const
    {
        return Queue(deque->Reduce(f, initial));
    }

    Queue<T, S> Concat(const Queue<T, S> & other) const
    {
        return Queue(deque->Concat(other.sequence));
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

    std::pair<Queue<T, S>, Queue<T, S>> Split(std::function<bool(const T &)> f) const
    {
        Queue right = Where(f);
        Queue wrong = Where([=](const T & a) { return !f(a); });
        return std::pair(right, wrong);
    }
private:
    Deque<T, S> deque;

    Queue(Deque<T, S> deque)
        : deque(deque) {}
};
