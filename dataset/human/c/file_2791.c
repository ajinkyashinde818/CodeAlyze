#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int cont =0;
    int k,s;
    scanf("%d %d",&k,&s);
    for(int i=0;i<=k;i++){
        for(int j= 0;j<=k;j++){
            int z = s-i-j;
            if(0<=z && z<=k)
                cont+=1;
        }
    }
    printf("%d\n",cont);

    return 0;
}
