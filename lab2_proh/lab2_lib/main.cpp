#include <iostream>
#include <deque.h>
#include <arraySequence.h>
#include <linkedListSequence.h>


using namespace std;




int main()
{
    Deque<int, ArraySequence<int>> deque;
    deque.PushBack(1);
    cout << deque.PopBack();
}
