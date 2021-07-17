#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int ball[3][100];
    int basket[101] = {
        0,
    };
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> ball[0][i] >> ball[1][i] >> ball[2][i];

    for (int i = 0; i < M; i++)
    {
        for (int j = ball[0][i]; j <= ball[1][i]; j++)
        {
            basket[j] = ball[2][i];
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d ", basket[i]);
}