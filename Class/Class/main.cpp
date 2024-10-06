#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{
    string response;
    int initialValue = 0;

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> response;

    if (response == "да") {
        cout << "Введите начальное значение счётчика: ";
        cin >> initialValue;
    }

    Counter counter(initialValue);

    char command;
    while (true)
    {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> command;

        if (command == '+') {
            counter.increment();
        } else if (command == '-') {
            counter.decrement();
        } else if (command == '=') {
            cout << counter.getValue() << endl;
        } else if (command == 'x') {
            cout << "До свидания!" << endl;
            break;
        } else {
            cout << "Неизвестная команда!" << endl;
        }
    }

    return 0;
}
