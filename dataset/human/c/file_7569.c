#include <stdio.h>
#define MAX 10000

int main(void){
    int i,j;
    int input[MAX];
    
    for(i=0;i<MAX;i++){
        scanf("%d",&input[i]);
        if(input[i]==0){
            break;
        }
        else if(input[i]<1||10000<input[i]){
            printf("error\n");
            return 0;
        }
    }
    
    for(j=0;j<i;j++){
        printf("Case %d: %d\n",j+1,input[j]);
    }
    
    return 0;
}
