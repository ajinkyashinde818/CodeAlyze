#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int min(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

int main(void){
    int n,i,j;
    int a[200000];
    int maxv=-2000000000;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int minv=a[0];
    for(i=0;i<n;i++){
        for(i=1;i<n;i++){
            maxv=max(maxv,a[i]-minv);
            minv=min(minv,a[i]);
        }
    }
    printf("%d\n",maxv);

    return 0;
}
