#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    if(*(long long*)a>*(long long *)b)return 1;
    return -1;
}
int main()
{   int n,r,g,b,cnt=0;
    scanf("%d%d%d%d",&r,&g,&b,&n);
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
                if((n-i*r-j*g)%b==0&&n-i*r-j*g>=0){
                    cnt++;
            }
        }
    }
    printf("%d",cnt);
    
    return 0;
}
