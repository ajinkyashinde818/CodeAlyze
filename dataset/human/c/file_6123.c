#include<stdio.h>
#define A 200000
int main(void){
    int n,s,t,u;
    int D[A];
    scanf("%d",&n);
    for(s=0;s<n;s++){
        scanf("%d",&D[s]);
    }
    for(s=0;s<n-1;s++){
        if(s==0 || t>D[s]){
            t=D[s];
        }
        if(s==0 || u<D[s+1]-t){
            u=D[s+1]-t;
        }
    }
    printf("%d\n",u);
    return 0;
}
