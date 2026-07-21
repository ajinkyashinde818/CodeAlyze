# include <stdio.h>

int main(void)
{
    int N,D,X;
    int i,j,k,l;
    scanf("%d",&N);
    scanf("%d %d",&D,&X);

    int array[N];

    for(i=0;i<N;i++){
        scanf("%d",&array[i]);
    }

    k=0;

    for(j=0;j<N;j++){
        l=0;
        while(array[j]*l+1<=D){
            l=l+1;
        }
        k=k+l;
    }
    k=k+X;

    printf("%d",k);

    return 0;
}
