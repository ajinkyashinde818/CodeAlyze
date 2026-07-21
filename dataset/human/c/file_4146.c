#include<stdio.h>
int main()
{
    int A,B,K;
//    int r,tmp;
    int count = 0;

    scanf("%d %d %d", &A,&B,&K);

    int c;


    for(int i = A;count<K;i--){
        if(A%i==0 && B%i==0){
            count++;
            c = i;
        }
    }
    printf("%d\n",c);
    return 0;

}
