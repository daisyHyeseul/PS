#include <stdio.h>
#include <iostream>

using namespace std;

void func(int a)
{

    int tmp = a;
    int b = 0;
    while (tmp)
    {
        b = b * 10 + tmp % 10;
        tmp /= 10;
    }
    //printf("%d\n", b);
    int sum = a + b;
    int result = 0;
    tmp = sum;
    while (tmp)
    {
        result = result * 10 + tmp % 10;
        tmp /= 10;
    }
    if (sum == result)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int T;
    int num[100000];
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < T; i++)
    {
        func(num[i]);
    }
}
