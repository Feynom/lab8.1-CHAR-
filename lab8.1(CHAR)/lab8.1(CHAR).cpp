#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

int Count(char* str);
char* Change(char* str);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[201];

    cout << "Введіть строку: ";
    cin.getline(str, 200); cout << endl;

    cout << "Число входжень в послідовність групи букв 'while': " << Count(str) << endl;

    char* second = new char[121];
    second = Change(str);

    cout << "Модифікований строка: " << second;

    return 0;
}
int Count(char* str)
{
    int k = 0; 
    int pos = 0;
    char* t;
    
    while (t = strchr(str + pos, 'w'))
    {
        pos = t - str + 1;
        if (str[pos] == 'h' &&
            str[pos + 1] == 'i' &&
            str[pos + 2] == 'l' &&
            str[pos + 3] == 'e')
            k++;
    }
    return k;  
}
char* Change(char* str)
{
    char* tmp = new char[strlen(str)];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *tmp = 0;

    while (p = strchr(str + pos1, 'w'))
    {
        if (str[p - str + 1] == 'h' &&
            str[p - str + 2] == 'i' &&
            str[p - str + 3] == 'l' &&
            str[p - str + 4] == 'e')
        {
            pos2 = p - str + 5;
            strncat(tmp, str + pos1, pos2 - pos1 - 5);
            strcat(tmp, "***");
            pos1 = pos2;
        }
    }
    strcat(tmp, str + pos1);

    strcpy(str, tmp);

    return tmp;
}
