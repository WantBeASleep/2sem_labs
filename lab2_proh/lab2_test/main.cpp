#include <QTest>

#include "tst_arraysequencetest.h"
#include "tst_linkedlistsequencetest.h"
#include "tst_dequetest.h"

template <typename TestClass>
void runTests(int argc, char* argv[], int* status)
{
    QCoreApplication app(argc, argv);
    TestClass tc;
    *status |= QTest::qExec(&tc, argc, argv);
}

int main(int argc, char* argv[])
{
    int status;
    runTests<ArraySequenceTest>(argc, argv, &status);
    runTests<LinkedListSequenceTest>(argc, argv, &status);
    runTests<DequeTest>(argc, argv, &status);
    return status;
}
