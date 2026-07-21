#include <stdio.h>

int main(void)
{
    int k=0,n=0,sum=0,max=0,temp=0,sub=0;
    int array[200001]={};

    scanf("%d %d",&k,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    array[n]=k+array[0];

    for(int i=0;i<n;i++){
        sub=array[i+1]-array[i];
        sum+=sub;
        if(sub>max){
            max=sub;
            temp=i;
        }
    }
    sum-=array[temp+1]-array[temp];

    printf("%d",sum);

    return 0;
}
