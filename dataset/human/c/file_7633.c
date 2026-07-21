#include <stdio.h>

int main(){
    int i = 0, j;
    int nm[10000];
    
    scanf("%d", &nm[i]);
    while(nm[i] != 0){
        i++;
        scanf("%d", &nm[i]);
    }


    for(j = 0; j < i; j++){
        printf("Case %d: %d\n", j+1, nm[j]);
    }
    
    return 0;
}
