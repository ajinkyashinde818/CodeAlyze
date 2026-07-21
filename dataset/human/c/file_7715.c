#include <stdio.h>
#include <math.h>
int main(){
    int i,j,tmp;
    int numdata[10000];
    for(i = 0;i<=10000;i++){
        scanf("%d",&tmp);
        if(tmp==0) break;
        if(tmp<=10000) numdata[i]=tmp; 
    }
    for(j=0;j<i;j++){
        printf("Case %d: %d\n",j+1,numdata[j]);
    }
    return 0;
}
