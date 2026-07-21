//1:18
#include <stdio.h>
#include <string.h>
#include <algorithm>

typedef long long ll;
ll max(ll a, ll b){return(a>b)?a:b;}
ll min(ll a, ll b){return(a<b)?a:b;}
ll abs(ll a){return(a<0)?-a:a;}

ll gcd(ll a, ll b){
        if(b > a){
                ll tmp = b;
                b = a;
                a = tmp;
        }
        if(b == 0) return a;
        else return gcd(b, a%b);
}
ll lcm(ll a, ll b){
        ll gcdi = gcd(a,b);
        return a/gcdi*(b);
}

ll a[2*100000];
int main(){
        int N;
        scanf("%d",&N);

        ll totalsum = 0;
        for(int i = 0; i < N; i ++){
                scanf("%lld",a+i);
                totalsum += a[i];
        }

        ll sum = 0;
        ll minab = 4000000000LL*100000LL+1LL;
        for(int i = 0; i < N-1; i ++){
                sum += a[i];
                if(minab > abs(2*sum-totalsum)){
                        minab = abs(2*sum-totalsum);
                }
        }
        printf("%lld\n",minab);

}
