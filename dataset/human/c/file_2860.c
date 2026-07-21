#include <stdio.h>

int main(void){
    int k,s,i,j,l;
    scanf("%d %d",&k,&s);
    int count = 0;
    for(int i = 0;i<=k;i++){
        for(int j = 0;j<=k;j++){
            // printf("i = %d j = %d\n",i,j);
            if(s - i - j <= k && s - i - j >= 0){
                count++;
                // printf("maru\n");
            }
        }
    }
    printf("%d\n",count);
}
