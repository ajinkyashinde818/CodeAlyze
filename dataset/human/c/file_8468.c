#include <stdio.h>

int main(void){
    int N,M,i,o,temp,line[100];
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)
        scanf("%d",&line[i]);
    for(i=1;i<=M;i++){
        for(o=0;o<N-1;o++){
            if(line[o]%i > line[o+1]%i){
                temp=line[o];
                line[o]=line[o+1];
                line[o+1]=temp;
            }
        }
    }
    for(i=0;i<N;i++)
        printf("%d\n",line[i]);
    return 0;
}
