#pragma once

#include <QtTest>
#include <arraySequence.h>
#include <linkedListSequence.h>
#include <exception>


class LinkedListSequenceTest : public QObject
{
    Q_OBJECT

public:
    LinkedListSequenceTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_init_fromArray();
    void test_Get_exception();
    void test_Insert_atTheBeginning();
    void test_Insert_atTheEnd();
    void test_Insert_atRandom();
    void test_GetSubsequence();
    void test_Concat_withLinkedListSequence();
    void test_Concat_withArraySequence();
    void test_Map();
    void test_Where();
    void test_Reduce();
    void test_Set();
};
