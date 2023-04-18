#include "tst_linkedlistsequencetest.h"

#include <arraySequence.h>
#include <linkedListSequence.h>
#include <exception>


LinkedListSequenceTest::LinkedListSequenceTest() {}

void LinkedListSequenceTest::initTestCase() {}
void LinkedListSequenceTest::cleanupTestCase() {}
void LinkedListSequenceTest::test_init_fromArray()
{
    int arr[] = {1,2,3};
    LinkedListSequence<int> seq(arr, 3);
    QCOMPARE(seq.GetLength(), 3);
    for(int i = 0; i < seq.GetLength(); ++i)
    {
        QCOMPARE(seq[i], arr[i]);
    }
}

void LinkedListSequenceTest::test_Get_exception()
{
int arr[] = {1,2,3};
LinkedListSequence<int> seq(arr, 3);
try
{
    seq.Get(4);
    QFAIL("Not exception occured");
}
catch(std::out_of_range & e)
{

}
}

void LinkedListSequenceTest::test_Insert_atTheBeginning()
{
    LinkedListSequence<int> seq;
    seq.Append(1);
    QCOMPARE(seq[0], 1);
}

void LinkedListSequenceTest::test_Insert_atTheEnd()
{
    LinkedListSequence<int> seq;
    seq.Prepend(1);
    QCOMPARE(seq[0], 1);
}

void LinkedListSequenceTest::test_Insert_atRandom()
{
    int arr[] = {1,2,3};
    LinkedListSequence<int> seq(arr, 3);
    seq.InsertAt(4, 2);
    QCOMPARE(seq[2], 4);
}

void LinkedListSequenceTest::test_GetSubsequence()
{
    int arr[] = {1,2,3,4,5};
    LinkedListSequence<int> seq(arr, 5);
    auto subseq = seq.GetSubsequence(2,4);
    for(int i=0; i<subseq->GetLength(); ++i)
    {
        QCOMPARE(subseq->Get(i), seq[i+2]);
    }
    delete subseq;
}

void LinkedListSequenceTest::test_Concat_withLinkedListSequence()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5};
    LinkedListSequence<int> seq1(arr1, 5);
    LinkedListSequence<int> seq2(arr2, 5);
    auto result = seq1.Concat(&seq2);
    for(int i=0; i<seq1.GetLength(); ++i)
    {
        QCOMPARE(seq1[i], result->Get(i));
    }
    for(int i=0; i<seq2.GetLength(); ++i)
    {
        QCOMPARE(seq2[i], result->Get(seq1.GetLength()+i));
    }
    delete result;
}

void LinkedListSequenceTest::test_Concat_withArraySequence()
{
    int arr1[] = {1,2,3};
    int arr2[] = {4,5};
    LinkedListSequence<int> seq1(arr1, 3);
    ArraySequence<int> seq2(arr2, 2);
    auto result = seq1.Concat(&seq2);
    for(int i=0; i<seq1.GetLength(); ++i)
    {
        QCOMPARE(seq1[i], result->Get(i));
    }
    for(int i=0; i<seq2.GetLength(); ++i)
    {
        QCOMPARE(seq2[i], result->Get(seq1.GetLength()+i));
    }
    delete result;
}

void LinkedListSequenceTest::test_Map()
{
    int arr[] = {1,2,3,4,5};
    LinkedListSequence<int> seq(arr, 5);
    auto result = seq.Map([](int x){return x+1;});
    for(int i=0; i<seq.GetLength(); ++i)
    {
        QCOMPARE(seq[i]+1, result->Get(i));
    }
    delete result;
}

void LinkedListSequenceTest::test_Where()
{
    int arr[] = {1,2,3,4,5};
    LinkedListSequence<int> seq(arr, 5);
    auto result = seq.Where([](int x){return x%2==0;});
    QCOMPARE(result->GetLength(),2);
    QCOMPARE(result->Get(0),2);
    QCOMPARE(result->Get(1),4);
    delete result;
}

void LinkedListSequenceTest::test_Reduce()
{
    int arr[] = {1,2,3,4,5};
    LinkedListSequence<int> seq(arr, 5);
    int result = seq.Reduce([](int val, int acc){return acc+val;}, 0);
    QCOMPARE(result, 1+2+3+4+5);
}

void LinkedListSequenceTest::test_Set()
{
    int arr[] = {1,2,3,4,5};
    LinkedListSequence<int> seq(arr, 5);
    seq[2] = arr[2] = 0;

    for(int i=0; i<seq.GetLength(); ++i)
    {
        QCOMPARE(seq[i], arr[i]);
    }
}



//#include "tst_linkedlistsequencetest.moc"
