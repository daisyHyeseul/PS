#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *num = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", num + i);
    }
    int k = 2;
    int flag = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        //  printf("n = %d ", *(num + i));
        while (k <= (*(num + i)) / 2)
        {
            //   printf("k = %d ", k);
            if (*(num + i) % k == 0)
            {
                flag = 1;
                break;
            }
            k++;
            // printf("flag = %d \n", flag);
        }
        if (!flag && *(num + i) != 1)
        {
            cnt++;
            //printf("n=%d count++\n", *(num + i));
        }
        k = 2;
        flag = 0;
    }
    printf("%d", cnt);

    return 0;
}