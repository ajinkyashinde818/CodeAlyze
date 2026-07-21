#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(void){
    int *attendance;
    int days;
    int rest;
    int num;
    int eat=0;

    scanf("%d",&num);
    scanf("%d %d",&days,&rest);
    attendance=(int *)malloc(sizeof(int)*num);

    int i,j;
    for(i=0;i<num;i++){
        scanf("%d",&attendance[i]);
        for(j=0;(j*attendance[i]+1)<=days;j++){
            eat++;
        }
    }
    printf("%d",rest+eat);
    return 0;

}
