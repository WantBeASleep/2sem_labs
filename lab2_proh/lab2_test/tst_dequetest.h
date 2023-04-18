#pragma once

#include <QTest>
#include <deque.h>

class DequeTest : public QObject
{
    Q_OBJECT

public:
    DequeTest();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_PushBack_PopBack();
    void test_PushBack_PopFront();
    void test_PushFront_PopFront();
    void test_PushFront_PopBack();
    void test_GetSize();
    void test_Concat();
    void test_GetSubSequence();
    void test_Map();
    void test_Where();
    void test_FindSubSequence();
};
