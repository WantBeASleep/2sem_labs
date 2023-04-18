#pragma once

#include <string>
#include <iostream>
#include <functional>
#include <limits>
#include <person.h>

template <class T>
T interractiveInput(
        std::string prompt = "",
        std::function<bool(const T &)> check = [](T _){return true;})
{
    using namespace std;
    while(true)
    {
        cout << prompt << ": ";
        T t;
        cin >> t;
        if(cin.good() && check(t))
        {
            return t;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again.\n";
    }
}

template <>
std::string interractiveInput(std::string prompt, std::function<bool(const std::string &)> check)
{
    using namespace std;
    while(true)
    {
        cout << prompt << ": ";
        string str;
        getline(cin, str);
        if(cin.good() && check(str))
        {
            return str;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(1);
        cout << "Invalid input. Try again.\n";
    }
}

template <>
Person interractiveInput(std::string prompt, std::function<bool(const Person &)> check)
{
    using namespace std;
    cout << prompt << " {\n";
    string firstName = interractiveInput<string>("First name");
    string middleName = interractiveInput<string>("Middle name");
    string lastName = interractiveInput<string>("Last name");
    unsigned passportSeries = interractiveInput<unsigned>("Passport series");
    unsigned passportNumber = interractiveInput<unsigned>("Passport number");
    cout << "}\n";
    return Person(PersonId(passportSeries, passportNumber), firstName, middleName, lastName);
}
