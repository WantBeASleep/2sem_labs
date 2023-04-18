#include <iostream>
#include <interractiveInput.h>
#include <menu.h>
#include <complex>
#include <person.h>
#include <queue.h>
#include <arraySequence.h>
#include <linkedListSequence.h>

using namespace std;

template <class T, class S>
void interractiveDequeCommand()
{
    Deque<T,S> deque;

    enum Command {
        EXIT,
        PUSH_BACK,
        PUSH_FRONT,
        POP_BACK,
        POP_FRONT,
        GET_SIZE,
        GET_SUBSEQUENCE,
        FIND_SUBSEQUENCE,
    };
    auto menu = Menu<Command>({
        {PUSH_BACK, "Push back"},
        {PUSH_FRONT, "Push front"},
        {POP_BACK, "Pop back"},
        {POP_FRONT, "Pop front"},
        {GET_SIZE, "Get size"},
        {GET_SUBSEQUENCE, "Get subsequence"},
        {FIND_SUBSEQUENCE, "Find subsequence"},
        {EXIT, "Exit"},
    });
    while(true)
    {
        cout << "\n";
        Command command = menu.prompt("Choose command");

        if(command == EXIT)
        {
            return;
        }

        if(command == PUSH_BACK)
        {
            T value = interractiveInput<T>("Enter value");
            deque.PushBack(value);
        }

        if(command == PUSH_FRONT)
        {
            T value = interractiveInput<T>("Enter value");
            deque.PushFront(value);
        }

        if(command == POP_BACK)
        {
            if(deque.GetSize() == 0) {
                cout << "Error. No values in the deque.\n";
            } else {
                cout << "Popped value = " << deque.PopBack() << "\n";
            }
        }

        if(command == POP_FRONT)
        {
            if(deque.GetSize() == 0) {
                cout << "Error. No values in the deque.\n";
            } else {
                cout << "Popped value = " << deque.PopFront() << "\n";
            }
        }

        if(command == GET_SIZE)
        {
            cout << "Deque size = " << deque.GetSize() <<  "\n";
        }

        if(command == GET_SUBSEQUENCE)
        {
            int indexesCount = interractiveInput<int>(
                        "Enter indexes count",
                        [=](int count) {return count >= 0 && count <= deque.GetSize();}
            );
            vector<int> indexes(indexesCount);
            for(int i = 0; i < indexesCount; ++i)
            {
                int index = interractiveInput<int>(
                    "Enter index " + to_string(i),
                    [=](int index){return (0 <= index && index < deque.GetSize());}
                );
                indexes[i] = index;
            }
            auto subsequence = deque.GetSubSequence(indexes);
            cout << *subsequence << "\n";
            delete subsequence;
        }

        if(command == FIND_SUBSEQUENCE)
        {
            S subsequence;
            int subsequenceLength = interractiveInput<int>(
                        "Enter subsequence length",
                        [=](int count) {
                return count >= 0 && count <= deque.GetSize();
            });
            for(int i = 0; i < subsequenceLength; ++i)
            {
                subsequence.Append(interractiveInput<T>(
                    "Enter [" + to_string(i) + "]"
                ));
            }
            int index = deque.FindSubSequence(subsequence);
            if(index == -1) {
                cout << "No such subsequence\n";
            } else {
                cout << "Subsequence found. Beginning index = " << index << "\n";
            }
        }
    }
}

template <class T>
void interractiveDequeRealization()
{
    enum ContainerRealization
    {
        ARRAY,
        LINKED_LIST,
    };

    ContainerRealization realization = Menu<ContainerRealization>({
       {ARRAY, "array"},
       {LINKED_LIST, "linked list"},
    }).prompt("Choose container realization type");

    switch(realization)
    {
    case ARRAY:
        interractiveDequeCommand<T, ArraySequence<T>>();
        break;
    case LINKED_LIST:
        interractiveDequeCommand<T, LinkedListSequence<T>>();
        break;
    }
}


int main()
{
    enum DataType
    {
        INTEGER,
        FLOATING_POINT,
        COMPLEX,
        PERSON,
    };
    DataType dataType = Menu<DataType>({
       {INTEGER, "Integer"},
       {FLOATING_POINT, "FloatingPoint"},
       {COMPLEX, "Complex"},
       {PERSON, "Person"},
    }).prompt();
    switch (dataType)
    {
    case INTEGER:
        interractiveDequeRealization<int>();
        break;
    case FLOATING_POINT:
        interractiveDequeRealization<double>();
        break;
    case COMPLEX:
        interractiveDequeRealization<complex<double>>();
        break;
    case PERSON:
        interractiveDequeRealization<Person>();
        break;
    }
    return 0;
}
