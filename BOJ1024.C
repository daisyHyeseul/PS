#include <stdio.h>

int main()
{
    unsigned long long N;
    int L, i;
    long double a;
    scanf("%lld %d", &N, &L);
    for (float n = L; n <= 100; n++)
    {
        a = ((N * 2.0) / n - (n - 1)) / 2.0;
        //  printf("a = %f \n", a);
        if (a == int(a) && a >= 0)
        {
            for (i = 0; i < n; i++)
                printf("%d ", int(a) + i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}