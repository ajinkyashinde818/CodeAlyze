#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void){
    int n, k, s;
    int i;
    scanf("%d%d%d",&n ,&k ,&s);
        for(i=0;i<n;i++){
            if(i<k){
                printf("%d ",s);
            }
            else if(s == 1000000000){
                printf("1 ");
            }
            else{
                printf("%d ",s+1);
            }
        }
        printf("\n");
    return 0; 
}
