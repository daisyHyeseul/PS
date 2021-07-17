#include <stdio.h>

int main()
{
    int tmp = 0, cnt = 0;
    float a, d, k;
    scanf("%f %f %f", &a, &d, &k);
    float result = (k - a) / d + 1;
    if (result <= 0 || int(result) != result)
    {
        printf("X");
    }

    else
        printf("%d", int(result));
    return 0;
}