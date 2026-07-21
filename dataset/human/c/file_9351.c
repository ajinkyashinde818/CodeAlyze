#include<stdio.h>
int func(int n,int a[],int d){
    int sum=0,i,j;
    for(i=0; i<n; i++){
        j=0;
        while((j*a[i]+1)<=d){
            sum += 1;
            j++;
        }
    }
    return sum;
}

int main(void){
    int n,d,x,i,sum;
    scanf("%d",&n);
    scanf("%d %d",&d,&x);
    int a[n];

    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    sum = func(n,a,d);

    printf("%d\n",sum+x);

    return 0;
}
