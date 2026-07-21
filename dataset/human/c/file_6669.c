#include <stdio.h>

int main(void)
{
    int n;
    int i ,j;
    int maxv, minv;
    
    scanf("%d" , &n);
    
    int A[n];
    
    for (i = 0 ; i < n ; i++)
            scanf("%d" ,&A[i]);
    
    minv = A[0];
    maxv = -1999999999; /*ここの値を変えるとなぜかWrong_Answerになる(~~;)*/
    
    for (j = 1 ; j < n ; j++)
    {
        maxv = (maxv > A[j] - minv) ? maxv : A[j] - minv ;
        minv = (minv < A[j]) ? minv :A[j];
        
    }
    printf("%d\n" ,maxv);
    return (0);
    
}
