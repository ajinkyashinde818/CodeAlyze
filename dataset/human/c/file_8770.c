#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{

    int n;
    int num;
    long long A[200001];

    scanf("%d", &n);
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    }

    qsort(A, n, sizeof(long long), compare_int);
    long long sum = 1;
    if (num % 2 == 1)
    { //奇数の時
        if (A[0] < 0)
        {
            sum = A[0];
            //最大値が負　全部ふ
            for (int i = 0; i < num-1; i++)
            {
                sum = sum * A[1+i]%1000000007;
            }
        }
        else if (A[0] >= 0)
        {
            sum = A[0];
            int front=1;
            int last = n;
            for (int i = 0; i < num - 1; i = i + 2)
            {
                if(A[front] * A[front + 1]>A[last - 1] * A[last - 2]){
                    sum = (sum * A[front] % 1000000007 )* A[front + 1] % 1000000007;
                    front += 2;
                }
                else
                {
                    sum = (sum * A[last - 1] % 1000000007) * A[last - 2] % 1000000007;
                    last -= 2;
                }
            }
        }
    }
    else
    {
        int front = 0;
        int last = n;
        for (int i = 0; i < num - 1; i = i + 2)
        {
            if (A[front] * A[front + 1] > A[last - 1] * A[last - 2])
            {
                sum = (sum * A[front] % 1000000007)* A[front + 1] % 1000000007;
                front += 2;
            }
            else
            {
                sum = (sum * A[last - 1] % 1000000007) * A[last - 2] % 1000000007;
                last -= 2;
            }
        }
    }
    if(sum<0){
        sum += 1000000007;
    }
    printf("%lld", sum);
    printf("\n");
}
