#include<stdio.h>
    #include<stdlib.h>
    int main(){
    int N,i;
    long long x,y,z;
    int a[200001];
    scanf("%d",&N);
    for(i=0;i<N;i++){
    scanf("%d",&a[i]);
    y+=a[i];
    }
    x=a[0];
    y-=a[0];
    z=llabs(x-y);
    for(i=1;i<N-1;i++){
    x+=a[i];
    y-=a[i];
    if(llabs(x-y)<z) z=llabs(x-y);
    }
    printf("%lld\n",z);
    return 0;
    }
