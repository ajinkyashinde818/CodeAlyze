#include<stdio.h>

int main(void){
    int m,s;
    int i,j;
    int count=0;

    scanf("%d%d", &m,&s);

    for(i=0;i<=m;i++){
        for(j=0;j<=m;j++){
            if(i+j<=s && s-i-j<=m){
                count +=1;
            }
            
            
        }
    }

    printf("%d", count);

    return 0;
}
