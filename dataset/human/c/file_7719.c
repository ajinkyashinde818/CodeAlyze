#include <stdio.h>
int main(){
    int array[10000];
    for(int i=0;i < 10000;i++){
        scanf("%d",&array[i]);
        if(array[i] == 0){
            break;
        }
    }
    for(int i=0;i < 10000;i++){
        printf("Case %d: %d\n",i+1,array[i]);
        if(array[i] == 0){
            break;
        }
    }
    return 0;
}
