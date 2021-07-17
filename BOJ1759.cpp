#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
bool checkfun(char *a, int L);
void permu(char *a, char *target, int start, int level, int L, int C);
bool compare(char a, char b)
{
    return int(a) < int(b);
}

int main()
{
    int L, C;
    char alphabet[30] = {
        0,
    };
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> alphabet[i];

    sort(alphabet, alphabet + C, compare);
    char result[30] = {
        ""};
    //for (int i = 0; i <= C - L; i++)
    permu(alphabet, result, 0, 0, L, C);
}

bool checkfun(char *a, int L) //주어진 문자열이 암호일 수 있는가
{
    int cnt_v = 0; //모음개수
    int cnt_c = 0; //자음개수
    for (int i = 0; i < L; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
            cnt_v++;
        else
            cnt_c++;
    }
    if (cnt_v > 1 && cnt_c > 2)
        return true;
    else
        return false;
}

void permu(char *a, char *target, int start, int level, int L, int C)
{
    if (level == L)
    {
        if (checkfun(target, L))
            cout << target << "\n";
        return;
    }
    for (int i = start; i < C - L + level + 1; i++)
    {
        target[level] = a[i];
        //  printf("현재 문자 : %c start : %d level : %d \n", target[level], start, level);
        permu(a, target, i + 1, level + 1, L, C);
    }
}