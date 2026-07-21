#include <stdio.h>
int main(){
    int i, o[10000];
    for (i=0;i<10000;i++){
        scanf("%d", &o[i]);
        if (o[i]==0){
            break;
        }
    }
    for (i=0;i<10000;i++){
        if (o[i]==0){
            break;
        }
        else{
            printf("Case %d: %d\n", i+1,o[i]);
        }
    }
    return 0;
}
