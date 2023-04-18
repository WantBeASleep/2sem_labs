#pragma once
#include <string>
using namespace std;

class Menu{
    int len;
    string* choice;
public:
    Menu();
    Menu(int, string*);
    int Choice(string title);
};