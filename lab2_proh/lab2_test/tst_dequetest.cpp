#include "tst_dequetest.h"

#include <QTest>
#include <deque.h>


DequeTest::DequeTest() {}

void DequeTest::initTestCase() {}

void DequeTest::cleanupTestCase() {}

void DequeTest::test_PushBack_PopBack()
{
    Deque<int> deque;
    deque.PushBack(1);
    deque.PushBack(2);
    QCOMPARE(deque.PopBack(), 2);
    QCOMPARE(deque.PopBack(), 1);
}

void DequeTest::test_PushBack_PopFront()
{
    Deque<int> deque;
    deque.PushBack(1);
    deque.PushBack(2);
    QCOMPARE(deque.PopFront(), 1);
    QCOMPARE(deque.PopFront(), 2);
}

void DequeTest::test_PushFront_PopFront()
{
    Deque<int> deque;
    deque.PushFront(1);
    deque.PushFront(2);
    QCOMPARE(deque.PopFront(), 2);
    QCOMPARE(deque.PopFront(), 1);
}

void DequeTest::test_PushFront_PopBack()
{
    Deque<int> deque;
    deque.PushFront(1);
    deque.PushFront(2);
    QCOMPARE(deque.PopBack(), 1);
    QCOMPARE(deque.PopBack(), 2);
}

void DequeTest::test_GetSize()
{
    Deque<int> deque;
    deque.PushFront(1);
    deque.PushFront(2);
    QCOMPARE(deque.GetSize(), 2);
}

void DequeTest::test_Concat()
{
    Deque<int> deque1;
    deque1.PushBack(1);
    Deque<int> deque2;
    deque2.PushBack(2);
    auto result = deque1.Concat(deque2);
    QCOMPARE(result.PopFront(), 1);
    QCOMPARE(result.PopFront(), 2);
}

void DequeTest::test_GetSubSequence()
{
    Deque<int> deque;
    deque.PushBack(1);
    deque.PushBack(2);
    deque.PushBack(3);
    deque.PushBack(4);
    auto result = deque.GetSubSequence({0,2});
    QCOMPARE(result->Get(0), 1);
    QCOMPARE(result->Get(1), 3);
    delete result;
}

void DequeTest::test_Map()
{
    Deque<int> deque;
    deque.PushBack(1);
    deque.PushBack(2);
    auto result = deque.Map([](int x){return x+1;});
    QCOMPARE(result.PopFront(), 2);
    QCOMPARE(result.PopFront(), 3);
}

void DequeTest::test_Where()
{
    Deque<int> deque;
    deque.PushBack(1);
    deque.PushBack(2);
    auto result = deque.Where([](int x){return x==1;});
    QCOMPARE(result.PopFront(), 1);
}

void DequeTest::test_FindSubSequence()
{
    Deque<int> deque;
    deque.PushBack(1);
    deque.PushBack(2);
    ArraySequence<int> subseq;
    subseq.Append(2);
    int beginIndex = deque.FindSubSequence(subseq);
    QCOMPARE(beginIndex, 1);
}

