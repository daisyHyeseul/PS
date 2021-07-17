#include <stdio.h>
void func(int a);
int main()
{
    int tc;
    int N[100000];
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
        scanf("%d", N + i);
    for (int i = 0; i < tc; i++)
        func(N[i]);
}

void func(int a)
{
    int num[a + 1] = {
        0,
    };
    int i = 2;
    while (a != 1)
    {
        if (a % i == 0)
        {
            num[i]++;
            a /= i;
            continue;
        }
        i++;
    }
    for (int j = 2; j <= i; j++)
    {
        if (num[j] != 0)
            printf("%d %d\n", j, num[j]);
    }
}