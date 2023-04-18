#pragma once

#include <initializer_list>
#include <tuple>
#include <string>
#include <interractiveInput.h>

template <class E>
class Menu
{
public:
    Menu(std::initializer_list<std::pair<E, std::string>> valuesByText)
    {
        using namespace std;
        optionsCount = valuesByText.size();
        values = new E[optionsCount];
        texts = new string[optionsCount];

        for(size_t i = 0; i < optionsCount; ++i)
        {
            pair<E, string> pair = *(valuesByText.begin() + i);
            values[i] = pair.first;
            texts[i] = pair.second;
        }
    }

    E prompt(std::string prompt = "Choose an option from menu")
    {
        using namespace std;
        cout << prompt << "\n";
        for(size_t i = 0; i < optionsCount; ++i)
        {
            cout << i+1 << ")" << texts[i] << "\n";
        }

        while(true)
        {
            size_t optionNumber = interractiveInput<size_t>(
                        "Enter option number",
                        [=](size_t opt) {return 0 < opt && opt <= optionsCount;}
            );
            return values[optionNumber-1];
        }
    }

    ~Menu()
    {
        delete[] values;
        delete[] texts;
    }

private:
    size_t optionsCount;
    E* values;
    std::string* texts;
};
