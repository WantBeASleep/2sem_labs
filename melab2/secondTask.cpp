#include <iostream>
#include <string>
#include "Sequence.hpp"

#include "ArraySequence.hpp"
#include "DynamicArray.hpp"

#include "ListSequence.hpp"
#include "LinkedList.hpp"

using namespace std;

ArraySequence<int> arrSeq;
ListSequence<int> listSeq;
Sequence<int> *seq;

void mainMenu();
void Random(int *rows, int *colums);
void Print(int rows, int colums);
void SetMatrix(int rows, int colums);
void Scalar(int rows, int colums, int lambda);
void ChangeRows(int rows, int colums, int idx1, int idx2);
void ScalarRows(int rows, int colums, int idx, int lambda);
void CombinateRows(int rows, int colums, int idx1, int idx2, int lambda);

void secondTask()
{
  int rows;
  int colums;
  int choise;
  cout << "1.Array\n2.Linked List\n";
  cin >> choise;
  switch(choise)
  {
    case 1:
      seq = &arrSeq;
    case 2:
      seq = &listSeq;
      break;
  }

  choise = 1;
  while(choise)
  {
    mainMenu();
    cout << "Choise: ";
    cin >> choise;
    switch(choise)
    {
      case 1:
      {
        Random(&rows, &colums);
        break;
      }
      case 2:
      {
        cout << "Rows: ";
        cin >> rows;
        cout << "Colums: ";
        cin >> colums;
        SetMatrix(rows, colums);
        break;
      }
      case 3:
      {
        break;
      }
      case 4:
      {
        int lambda;
        cout << "Lambda: ";
        cin >> lambda;
        Scalar(rows, colums, lambda);
        break;
      }
      case 5:
      {
        break;
      }
      case 6:
      {
        int idx1, idx2;
        cout << "First: ";
        cin >> idx1;
        cout << "Second: ";
        cin >> idx2;
        ChangeRows(rows, colums, idx1, idx2);
        break;
      }
      case 7:
      {
        int idx, lambda;
        cout << "index: ";
        cin >> idx;
        cout << "lambda: ";
        cin >> lambda;
        ScalarRows(rows, colums, idx, lambda);
        break;
      }
      case 8:
      {
        int idx1, idx2, lambda;
        cout << "First: ";
        cin >> idx1;
        cout << "Second: ";
        cin >> idx2;
        cout << "lambda: ";
        cin >> lambda;
        CombinateRows(rows, colums, idx1, idx2, lambda);
        break;
      }
      case 9:
      {
        Print(rows, colums);
        break;
      }
      case 10:
      {
        Random(&rows, &colums);
        Print(rows, colums);
        int rLambda = rand() % 10 + 1;
        int rRow = rand() % rows;
        cout << "rRow: " << rRow << " rLambda: " << rLambda << endl;
        cout << "idx row: " << rRow << " умножим на lambda: " << rLambda << endl;
        ScalarRows(rows, colums, rRow, rLambda);
        Print(rows, colums);
        break;
      }
    }
  }
}

void mainMenu() 
{
  cout << "0. Exit" << endl;
  cout << "~~Задание матрицы~~" << endl;
  cout << "1. Random" << endl;
  cout << "2. Вручную" << endl;
  cout << "~~Операции~~" << endl;
  cout << "3. Сложение матриц" << endl;
  cout << "4. Умножение на скаляр" << endl;
  cout << "5. Вычисление нормы" << endl;
  cout << "~~Элементарные преобразования~~" << endl;
  cout << "6. Перестановка строк" << endl;
  cout << "7. Умножение строки на число" << endl;
  cout << "8. Прибавление к одной строке другой умноженной на число" << endl;
  cout << "~~~~" << endl;
  cout << "9. ВЫВОД" << endl;
  cout << "10. TEST" << endl;
}

void Print(int rows, int colums)
{
  cout << "Mtrx:\n";
  for (int i=0; i < rows; i++)
  {
    cout << "( ";
    for (int j=0; j < colums; j++)
    {
      cout << seq->Get(colums*i + j) << " ";
    }
    cout << ")\n";
  }
  cout << "\n";
}

void Random(int *rows, int *colums)
{
  *rows = rand() % 5 + 1;
  *colums = rand() % 5 + 1;
  cout << "rows: " << *rows << "\ncolums: " << *colums << endl;
  int size = (*rows)*(*colums);
  seq->Resize(size);
  for(int i = 0; i < size; seq->Set(i, rand() % 10), i++);
}

void SetMatrix(int rows, int colums)
{
  int size = rows*colums;
  seq->SetSequence(size);
}

void Scalar(int rows, int colums, int lambda)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < colums; j++)
    {
      seq->Set(colums*i + j, seq->Get(colums*i + j) * lambda);
    }
  }
}

void ChangeRows(int rows, int colums, int idx1, int idx2)
{
  for (int i = colums * idx1; i < colums * (idx1 + 1); i++)
  {
    int tmp = seq->Get(colums * idx2 + i);
    seq->Set(colums * idx2 + i, seq->Get(i));
    seq->Set(i, tmp);
  }
}

void ScalarRows(int rows, int colums, int idx, int lambda)
{
  for (int i = colums * idx; i < colums * (idx + 1); i++)
  {
    seq->Set(i, seq->Get(i) * lambda);
  }
}

void CombinateRows(int rows, int colums, int idx1, int idx2, int lambda)
{
  for (int i = colums * idx1; i < colums * (idx1 + 1); i++)
  {
    seq->Set(i, seq->Get(i) + seq->Get(colums * idx2 + i) * lambda);
  }
}