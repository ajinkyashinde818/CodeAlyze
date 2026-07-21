#include<stdio.h>
#define N 200000
int main(){
    int i;
    int n,maxv=-2000000000,minv;
    int R[N];
    
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&R[i]);
    
    minv = R[0];
    
    for(i=1;i<n;i++){
        maxv = maxv > R[i] - minv ? maxv : R[i] - minv;
        minv = minv < R[i] ? minv : R[i]; 
    }
    printf("%d\n",maxv);
    return 0;
}
