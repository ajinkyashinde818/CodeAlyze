#include<stdio.h>

int main(){
    int n,f[131072]={0},a[131072],i,nb=1,r=0;
    scanf("%d",&n);
    for(i = 1;i <= n;i++){scanf("%d",&a[i]);}
    while(1){
        f[nb]++;r++;
        nb=a[nb];
        if(nb == 2){printf("%d\n",r);return 0;}
        if(f[nb] > 0){printf("-1\n");return 0;}
    }
    return 0;
}
