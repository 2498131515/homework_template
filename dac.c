#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *Random(int n, int *a)
{
    a = (int *)realloc(a, sizeof(int) * n);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = rand();
        srand(*(a + i));
    }
    return a;
}
void swap(int *a, int i, int j)
{
    int b;
    b = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = b;
}
int bubble(int *a, int n)
{
    int k;
    int flag = 1;
    int count = 0;
    int m = n;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < m - 1; i++)
        {
            if (*(a + i) > *(a + i + 1))
            {
                swap(a, i, i + 1);
                count++;
                flag = 1;
            }
        }
        m--;
    }
    printf("%d\n", count);
}
void MergeList(int *a, int start1, int end1, int start2, int end2,int *count)
{
    int n = end1 - start1 + 1;
    int m = end2 - start2 + 1;
    int l[n], r[m];
    for (int i = 0; i < n; i++)
    {
        l[i] = *(a + i + start1);
    }
    for (int i = 0; i < m; i++)
    {
        r[i] = *(a + i + start2);
    }
    int i = 0;
    int j = 0;
    int k = start1;
    while (i < n && j < m)
    {
        if (l[i] <= r[j])
        {
            *(a + k) = l[i];
            k++;
            i++;
        }
        else
        {
            *(a + k) = r[j];
            k++;
            j++;
        }
        *count+=1;
    }
    while (i < n)
    {
        *(a + k) = l[i];
        k++;
        i++;
    }
    while (j < m)
    {
        *(a + k) = r[j];
        k++;
        j++;
    }
}
void Merge(int *a, int frist, int last,int *count)
{
    if (frist < last)
    {
        int middle = (frist + last) / 2;
        Merge(a, frist, middle,count);
        Merge(a, middle + 1, last,count);
        MergeList(a, frist, middle, middle + 1, last,count);
    }
}
void Quick(int *a, int start, int end, int *count)
{
    if (start >= end)
    {
        return;
    }
    int i = start;
    int j = end;
    while (i != j)
    {
        while (*(a + j) >= *(a + start) && i < j)
        {
            j--;
            *count += 1;
        }
        while (*(a + i) <= *(a + start) && i < j)
        {
            i++;
            *count += 1;
        }
        swap(a, i, j);
    }
    swap(a, i, start);
    Quick(a, start, i - 1, count);
    Quick(a, i + 1, end, count);
}
int main()
{
    int n, *a, count = 0;
    a = (int *)malloc(sizeof(int));
    printf("输入要生成的随机数数组大小:");
    scanf("%d", &n);
    a = Random(n, a);
    bubble(a, n);
    a = Random(n, a);
    Quick(a, 0, n - 1, &count);
    printf("%d\n", count);
    a = Random(n, a);
    count=0;
    Merge(a, 0, n - 1,&count);
    printf("%d\n", count);
}