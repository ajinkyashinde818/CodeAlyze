#include <stdio.h>
    int main(){
        int i=0,x=0,k;
        int data[10000];
        while(1){
            x++;
            scanf("%d",&data[x]);
            i=i+1;
            if(data[x] == 0)break;
        }
        for(k=1;k<i;k++){
            printf("Case %d: %d\n",k,data[k]);
    }
    return 0;
}
