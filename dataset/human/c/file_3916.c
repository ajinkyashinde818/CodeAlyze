#include <stdio.h>

int main(void){
    int a,b,i,j,k;
    int div[1000];
    j = 0;
    scanf("%d %d %d",&a,&b,&k);
    for (i=100;i>0;i--){
        if (a%i==0){
            if (b%i==0){
                div[j] = i;
                j++;
            }
        }
    }
    printf("%d",div[k-1]);
}
