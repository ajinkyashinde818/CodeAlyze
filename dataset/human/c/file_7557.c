#include<stdio.h>
int main(void)
{
        int i = 1,j,temp[10000];
        while(1){
                scanf("%d",&temp[i]);
                if(temp[i] == 0){
                        break;
                }
                i++;
        }
        for(j = 1;j <= i-1;j++){
                printf("Case %d: %d\n",j,temp[j]);
        }
        return 0;
}
