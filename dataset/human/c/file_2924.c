#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){

    char line[256];
    int K,S;
    int i,j,k;
    int count=0;

    fgets(line,sizeof(line),stdin);
    sscanf(line,"%d %d", &K,&S);

    for(i=0;i<=K;i++){
        for(j=0;j<=K;j++){
            k = S - (i+j);
            if(i+j+k == S && k <= K && k >= 0)count += 1;
        }
    }

    printf("%d",count);

    return 0;
}
