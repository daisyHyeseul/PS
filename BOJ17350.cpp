#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int num;
    char name[100];
    char target[4] = "anj";
    int result = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> name;
        if (!strcmp(target, name))
            result = 1;
    }
    if (result)
        cout << "뭐야;";
    else
        cout << "뭐야?";
}