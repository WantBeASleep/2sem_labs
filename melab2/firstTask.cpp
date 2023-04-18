#include <iostream>
#include <string>
#include "Sequence.hpp"

#include "ArraySequence.hpp"
#include "DynamicArray.hpp"

#include "ListSequence.hpp"
#include "LinkedList.hpp"

using namespace std;

ArraySequence<int> farrSeq;
ListSequence<int> flistSeq;
Sequence<int> *fSeq;

void fmainMenu();

void firstTask()
{
  int exLenght = 5;
  int exArr[] = {59, 81, 80, 49, 3};



  // Тип хранения даннных
  int choise;
  cout << "1.Array\n2.Linked List\n";
  cin >> choise;
  switch(choise)
  {
    case 1:
      fSeq = &farrSeq;
    case 2:
      fSeq = &flistSeq;
      break;
  }

  // Операции

  choise = 1;
  while(choise)
  {
    fmainMenu();
    cin >> choise;
    switch(choise)
    {
      case 1:
      {
        int lenght;
        cout << "lenght? - ";
        cin >> lenght;
        fSeq->SetSequence(lenght);
        break;
      }
      case 2:
      {
        int index, elem;
        cout << "index: ";
        cin >> index;
        cout << "elem: ";
        cin >> elem;
        fSeq->Set(index, elem);
        break;
      }
      case 3:
      {
        fSeq->GetExSequence(exLenght, exArr);
        break;
      }
      case 4:
      {
        int newLenght = 0;
        cout << "New Lenght: ";
        cin >> newLenght;
        fSeq->Resize(newLenght);
        break;
      }
      case 5:
      {
        int elem;
        cout << "new elem: ";
        cin >> elem;
        fSeq->Append(elem);
        break;
      }
      case 6:
      {
        int elem;
        cout << "new elem: ";
        cin >> elem;
        fSeq->Prepend(elem);
        break;
      }
      case 7:
      {
        int index, elem;
        cout << "index: ";
        cin >> index;
        cout << "elem: ";
        cin >> elem;
        fSeq->InsertAt(elem, index);
        break;
      }
      case 8:
      {
        cout << fSeq->GetFirst() << endl;
        break;
      }
      case 9:
      {
        cout << fSeq->GetLast() << endl;
        break;
      }
      case 10:
      {
        int index;
        cout << "index: ";
        cin >> index;
        cout << fSeq->Get(index) << endl;
        break;
      }
      case 11:
      {
        int idx1, idx2;
        cout << "idx1: ";
        cin >> idx1;
        cout << "idx2: ";
        cin >> idx2;
        Sequence<int> *subSeq = fSeq->GetSubsequence(idx1, idx2);
        subSeq->Print();

        int choise;
        cout << "Concat sequence? 0/1: ";
        cin >> choise;
        if (choise) break;

        fSeq->Concat(subSeq);

        break;
      }
      case 12:
      {
        cout << fSeq->GetLength() << endl;
        break;
      }
      case 13:
      {
        fSeq->Print();
        break;
      }
      case 14:
      {
        cout << "2-ой сиквенс через SubSequence" << endl;
        break;
      }
    }
  }
  return;
}

void fmainMenu() 
{
  cout << "0. Exit" << endl;
  cout << "~~Задание сиквенса~~" << endl;
  cout << "1. SetSequence(int size)" << endl;
  cout << "2. Set(int index, T item)" << endl;
  cout << "3. GetExSequence(int size, T* example)" << endl;
  cout << "~~Изменения сиквенса~~" << endl;
  cout << "4. Resize(int newSize)" << endl;
  cout << "5. Append(T item)" << endl;
  cout << "6. Prepend(T item)" << endl;
  cout << "7. InsertAt(T item, int index)" << endl;
  cout << "~~Декомпозиция~~" << endl;
  cout << "8. GetFirst()" << endl;
  cout << "9. GetLast()" << endl;
  cout << "10. Get(int index)" << endl;
  cout << "11. GetSubsequence(int startIndex, int endIndex)" << endl;
  cout << "12. GetLength()" << endl;
  cout << "13. Print()" << endl;
  cout << "~~Операции~~" << endl;
  cout << "14. Concat(Sequence<T>* list)" << endl;
}

