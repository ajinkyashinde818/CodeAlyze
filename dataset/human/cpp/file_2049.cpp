#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int n,a[100001],i,m=999999999;
    bool f=1;
    long long int r=0;
    cin >> n;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0){
            f^=1;
            a[i]=-a[i];
        }
        if(m>a[i])m=a[i];
        r+=a[i];
    }
    printf("%lld\n",r-2*m*(1-f));
}

int abs(int x){
    if(x<0)return -x;
    return x;
}
