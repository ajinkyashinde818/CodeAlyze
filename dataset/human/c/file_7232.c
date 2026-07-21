#include<stdio.h>
int main(){
    int a,b,i,j;
    while(1){
        scanf("%d %d",&a,&b);
        if(a==0 && b==0)break;
        for(i=1;i<=a;i++){
            for(j=1;j<=b;j++){
                if(i%2==1 && j%2==1){
                    printf("#");
                }
                else if(i%2==1 && j%2==0){
                    printf(".");
                }
                else if(i%2==0 && j%2==1){
                    printf(".");
                }
                else if(i%2==0 && j%2==0){
                    printf("#");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return (0);
}
