#include <stdio.h>

int main() {
    int x=0,i=0,data[10000];
    while(1){
        i++;
        scanf("%d",&data[i]);
        x=x+1;
        if(data[i]==0)break;
        
        }
    for(x=1;x<i;x++){
        printf("Case %d: %d\n",x,data[x]);
    }
    return 0;
}
