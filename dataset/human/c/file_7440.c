#include <stdio.h>
int main(void){
    int i,j,d;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            scanf("%d",&d);
            if(d==0){
                break;
            }else{
                printf("Case %d: %d\n",i*100+j+1,d);
            }
        }
    }
    return 0;
}
