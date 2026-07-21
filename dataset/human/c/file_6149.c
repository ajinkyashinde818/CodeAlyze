#include<stdio.h>

int main(void){
    int n,maxv,minv;
    scanf("%d", &n);
    int x[n];
    for(int i=0 ; i<n ; i++)    scanf("%d",&x[i]);
    
    maxv=x[1]-x[0], minv=x[0];

    for(int i=1 ; i<n ; i++){
        maxv=(maxv > x[i]-minv) ? maxv:(x[i]-minv);
        minv=(x[i] < minv) ? x[i]:minv;
    }
    printf("%d\n", maxv);
    return 0;
}
