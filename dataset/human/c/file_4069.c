#include <stdio.h>
int main(void)
{
    int A, B, k, i=1, length;
    scanf("%d%d%d", &A, &B, &k);
    char ans[100];
    while(i<=100)
    {
        if ((A%i==0)&&(B%i==0))
        {
            ans[length] = i;
            length++;
        }
        i++;
    }
    printf("%d\n", ans[length-k]);
}
