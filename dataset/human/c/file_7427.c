#include <stdio.h>

int main(void){
        int num[10000], i, j=0;
        for(i=0;i<10000;i++){
                scanf("%d", &num[i]);
                if(num[i]==0)
                        break;
                j++;
        }
        for(i=0;i<j;i++)
                printf("Case %d: %d\n", i+1, num[i]);
        return 0;
}
