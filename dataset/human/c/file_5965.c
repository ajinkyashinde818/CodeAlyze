#include<stdio.h>

int main(){
    int i,j,n,v,max=-1000000000,a[200001];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    v=a[0];
    for(i=0;i<n;i++){
        if(i>0){
            if(max < a[i]-v) max=a[i]-v;
        }
        if(v>a[i]) v=a[i];
    }
    printf("%d\n",max);
}
