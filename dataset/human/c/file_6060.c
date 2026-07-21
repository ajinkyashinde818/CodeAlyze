#include<stdio.h>

#define MAX 200000

int max(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int min(int a,int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int main(void){

    int n,R[MAX],min_R,max_R,i,dif;

    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&R[i]);
    }

    min_R = R[0];
    max_R = -2000000000;

    for(i = 1;i < n;i++){
        max_R = max(max_R , R[i] - min_R);
        min_R = min(min_R,R[i]);
    }

    printf("%d\n",max_R);
    return 0;
}
