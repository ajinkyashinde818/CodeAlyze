#include <iostream>
using namespace std;
#include <algorithm>
#include <math.h>
#include <stdio.h>
int main(void){
    long long a,b,c,i,j,k,y,z,n,m;
    scanf("%lld%lld",&n,&c);
    long long x[n],v[n];
    for(i=0;i<n;i++){
        scanf("%lld%lld",&x[i],&v[i]);
    }
    long long s[n+1],t[n+1];
    s[0]=0;
    for(i=0;i<n;i++){
        s[i+1]=s[i]+v[i];
    }
    y=0;
    for(i=0;i<n;i++){
        z=s[i+1]-x[i];
        if(y<z)y=z;
    }
    t[0]=0;
    for(i=0;i<n;i++){
        t[i+1]=t[i]+v[n-1-i];
    }
    for(i=0;i<n;i++){
        z=t[i+1]-(c-x[n-1-i]);
        if(y<z)y=z;
    }
    long long ss[n+1],tt[n+1];
    ss[0]=0;tt[0]=0;
    for(i=0;i<n;i++){
        ss[i+1]=s[i+1]-x[i];
        tt[i+1]=t[i+1]-(c-x[n-1-i]);
    }
    z=0;
    for(i=0;i<=n;i++){
        if(z<ss[i])z=ss[i];
        if(ss[i]<z)ss[i]=z;
    }
    z=0;
    for(i=0;i<=n;i++){
        if(z<tt[i])z=tt[i];
        if(tt[i]<z)tt[i]=z;
    }
    for(i=0;i<n;i++){
        z=s[i+1]-2*x[i]+tt[n-i-1];
        if(y<z)y=z;
    }
    for(i=0;i<n;i++){
        z=t[i+1]-2*(c-x[n-i-1])+ss[n-i-1];
        if(y<z)y=z;
    }
    printf("%lld\n",y);
}
