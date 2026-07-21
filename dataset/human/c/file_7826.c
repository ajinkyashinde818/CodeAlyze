#include<stdio.h>
int main()
{
    int n,x,w;
    scanf("%d",&n);
    int k[1][n],p[1][n];
    for(x=0;x<n;x++){
        scanf("%d %d",&k[0][x],&p[0][x]);
    }
    for(x=0;x<n;x++){
        w=k[0][x]%p[0][x];
        if(w==0){
            printf("%d\n",p[0][x]);
        }
        else{
            printf("%d\n",w);
        }
    }
    return 0;
}
