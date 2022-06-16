#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int dac_f(int n, int *count)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    *count += 1;
    return dac_f(n - 1, count) + dac_f(n - 2, count);
}
int dp_f(int n, int *count)
{
    int a[n];
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            a[i] =1;
        }
        else
        {
            *count += 1;
            a[i] = a[i -1 ] + a[i - 2];
        }
    }
    printf("\n");
    return a[n - 1];
}
int main()
{
    int n, count = 0;
    int res;
    printf("请输入n的值:\n");
    scanf("%d", &n);
    res=dac_f(n, &count);
    printf("%d  %d\n",res, count);
    count = 0;
    res=dp_f(n, &count);
    printf("%d  %d\n",res, count);
    return 0;
}