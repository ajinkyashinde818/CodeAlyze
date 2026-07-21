#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int *xs, int front, int back)
{
    int temp = xs[front];
    xs[front] = xs[back];
    xs[back] = temp;
}

bool isSwap(int nowBibs, int nextBibs, int baton)
{
    return (nowBibs % baton) > (nextBibs % baton);
}

void printIntArray(int *arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void batonRelay(int *arr, int num, int baton)
{
    for (int i = 0; i < num - 1; i++)
    {
        if (isSwap(arr[i], arr[i + 1], baton))
        {
            swap(arr, i, i + 1);
        }
    }
}

int main()
{
    int nm[2];
    scanf("%d"
          "%d",
          &nm[0], &nm[1]);

    int studentNum = nm[0];
    int batonNum = nm[1];

    int students[studentNum];

    for (int i = 0; i < studentNum; i++)
    {
        scanf("%d", &students[i]);
    }

    for (int bi = 0; bi < batonNum; bi++)
    {
        batonRelay(students, studentNum, bi + 1);
    }

    printIntArray(students, studentNum);

    return 0;
}
