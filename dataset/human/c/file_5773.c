#include<stdio.h>
int main(void)
{
    int n;
    signed int maxv,minv;
    int S[200000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    minv=S[0];
    maxv=-1;
    for(int i=1;i<n;i++){
        if(maxv<=(S[i]-minv)){
            maxv=S[i]-minv;
        }
        if(minv>=S[i]){
            minv=S[i];
        }
    }
    if(n<=2){
        maxv=S[1]-S[0];
    }
    printf("%d\n",maxv);
    return 0;
}
