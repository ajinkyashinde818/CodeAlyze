#include <stdio.h>

int main (void){
    int count=0;
    int i;
    int memory[100000];
    while(1){
        scanf("%d",&memory[count]);
        if(memory[count]==0){
            break;
        }
        else{
            count++;
        }
    }

    for(i=0;i<count;i++){
        printf("Case %d: %d\n",i+1,memory[i]);
    }
    return 0;
}
