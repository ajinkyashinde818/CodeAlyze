//b.c -- Buffet
#include<stdio.h>

int main(void){
    int n,manzoku=0;
    scanf("%d",&n);
    int a[100],b[100],c[100];
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int j=0;j<n;++j){
        scanf("%d",&b[j]);
    }
    for(int k=0;k<n-1;++k){
        scanf("%d",&c[k]);
    }
    for(int l=0;l<n;++l){
        int m = a[l];
        if(l!=0 && a[l] - a[l-1] == 1){
            manzoku += b[m-1];
            manzoku += c[a[l-1]-1];
        }else{
            manzoku += b[m-1];
        }
    }


    printf("%d",manzoku);
    return 0;
}
