#include <stdio.h>

int main(void){
    int n,k,p,i;
    scanf("%d",&n);
    int w[n];
    for(i=0;i<n;i++){
        scanf("%d %d",&k,&p);
        if(k%p==0)
            w[i]=p;
        else
            w[i]=k%p;
    }
    for(i=0;i<n;i++)
        printf("%d\n",w[i]);
    return 0;
}
