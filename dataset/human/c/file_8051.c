#include <stdio.h>
long long gcd(long long a,long long b){
    long long c;
    if(a<b){
        a+=b;
        b=a-b;
        a-=b;
    }
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main(){
    int t;
    scanf("%d",&t);
    long long a,b,c,d;
    long long x,y;
    for(int i=0;i<t;i++){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
         y=(a-c-1)/b;
            if(a<=c)y=0;
            y++;
            a-=b*y;
        if(a<0||d<b){
            printf("No\n");
        }else{
            if(d==b){
                if(c>=a%b)printf("Yes\n");
                else printf("No\n");
            }
            else{
                x=gcd(d-b,b);
                y=(c-a)/x;
                if(a+(y+1)*x-b<0)printf("No\n");
                else printf("Yes\n");
            }
        }
    }
}
