#include<stdio.h>

int main(){

    int c=0,i,n;
    long long int a[100000],b[100000],max=0,min=1000000000;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<0){
            c++;
            b[i]=-1*a[i];
        }else b[i]=a[i];
        if(min>b[i])min=b[i];
    }

    if(c%2){
        for(i=0;i<n;i++){
            if(a[i]<0)a[i]=-1*a[i];
            max+=a[i];
        }
        max=max-2*min;
    }else{
        for(i=0;i<n;i++){
            if(a[i]<0)a[i]*=-1;
            max+=a[i];
        }
    }
    printf("%lld\n",max);
    return 0;
}
