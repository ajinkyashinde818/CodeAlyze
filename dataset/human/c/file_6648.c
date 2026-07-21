#include<stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    int R[200000];
    int i;
    for(i=0;i<n;i++){
        scanf("%d\n",&R[i]);
    }
    int min=R[0];
    int max=-1000000000;
    for(i=1;i<n;i++){
        if((R[i]-min)>max){
            max=R[i]-min;
        }
        if(R[i]<min){
            min=R[i];
        }
    }
    printf("%d\n",max);
    return 0;
}
