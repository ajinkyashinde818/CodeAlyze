#include<stdio.h>
int main(){
    int i,num,N,min=1000000000,max=-1000000000,min_num;
    
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&num);
        if(num - min > max && i>=1){
            max = num-min;
        }
        if(min > num){
            min = num;
        }
    }
    printf("%d\n",max);
}
