#include <iostream>
#include "Menu.hpp"

Menu::Menu() {
    len = 0;
    choice = NULL;
}

Menu::Menu(int quantity, string* strings) {
    len = quantity;
    choice = new string[len];
    for (int i = 0; i < len; i++) {
        choice[i] = strings[i];
    }
}

int Menu::Choice(string title) {
    //system("cls");
    char chr;
    do{
        for (int i = 0; i < len; i++) {
            cout << i + 1 << ". " << choice[i] << endl;
        }
            cout<< "Enter number || Press 0 to Exit : ";
            cin >> chr;
            cout << endl;
        } while ((chr<'0') || chr > ((char)'0' + len));
    return (int)chr - '0';
}

