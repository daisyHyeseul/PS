#include <stdio.h>
#include <iostream>

using namespace std;
int Rev(int a);

int main()
{
    int X, Y;
    cin >> X >> Y;
    int tmp = Rev(X) + Rev(Y);
    cout << Rev(tmp);
}

int Rev(int a)
{
    int result = 0;
    while (a)
    {
        result = result * 10 + a % 10;
        a /= 10;
    }

    return result;
}