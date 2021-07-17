#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
    unsigned long long num;
    stack<int> bin;

    scanf("%lld", &num);
    while (num)
    {
        bin.push(num % 2);
        num /= 2;
    }

    while (!bin.empty())
    {
        printf("%d", bin.top());
        bin.pop();
    }
    return 0;
}
