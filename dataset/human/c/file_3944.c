#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    if(*(long long *)a>*(long long*)b)return 1;
    return -1;
}
long long Max(long long a,long long  b){
    if(a>b )return a;
    return b;
}
long long Min(long long  a,long long  b){
    if(a<b )return a;
    return b;
}
int main()
{   int a,b,c,n,k,i,m=0,x[100]={0},y;
    scanf("%d%d%d",&a,&b,&k);
    for(i=1;i<=Min(a,b);i++){
        if(a%i==0&&b%i==0){
            x[m]=i;
            m++;
        }
    
    }
    for(i=m;i>=0;i--){
        if(m-i==k){
            printf("%d",x[i]);
            return 0;
        }
    }
    return 0;
}
