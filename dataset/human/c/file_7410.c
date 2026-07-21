#include <stdio.h>
int main(){

    int x[10000];
    int i=0;
    int j;
    
    while(1){
        i++;
        scanf("%d",&x[i]);
        
        if(x[i]==0){
            break;
        }
    }
    
    for(j=1;j<i;j++){
        printf("Case %d: %d\n",j,x[j]);
    }
    return 0;
}
