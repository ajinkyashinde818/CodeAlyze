#include<stdio.h>

int n,x[200000],maxv,minv;

void max(){
    maxv=x[1]-x[0], minv=x[0];

    for(int i=1 ; i<n ; i++){
        maxv=(maxv > x[i]-minv) ? maxv:(x[i]-minv);
        minv=(x[i] < minv) ? x[i]:minv;
    }
    printf("%d\n", maxv);
}

int main(void){
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++)
        scanf("%d",&x[i]);
    max();
    return 0;
}
