#include <stdio.h>

int gcd(int a,int b){
    if(a<b) gcd(b,a);
    int g;
    while(g=a%b){
        a=b;
        b=g;
    }
    return b;
}

int main(){
    int a,b,k;scanf("%d%d%d",&a,&b,&k);
    int g=gcd(a,b);
    int i=0;
    while(k>0){
      i++;
      k-=g%i?0:1;
    }
    printf("%d",g/i);
    return 0;
}
