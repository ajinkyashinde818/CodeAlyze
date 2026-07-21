#include<stdio.h>


int main(void){

    int N=10,count=0,judge=0;
    scanf("%d",&N);
    
    int a[N],b[N];

    for(int n=0;n<N;n++){
        scanf("%d %d",&a[n],&b[n]);
    }


    for(int n=0;n<N;n++){
        if(a[n]==b[n])count++;
        else count=0;
        //printf("%d ",count);
        if(count==3)judge=1;
    }


    if(judge==1)printf("Yes");
    else printf("No");
    return 0;
}
