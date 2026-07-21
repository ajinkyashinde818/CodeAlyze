//1:10
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

//int a[200000];
//int b[200000];
int a, b;
#define MAXI 2000001
int c[MAXI];
int main(){
        int N,M;
        scanf("%d %d",&N,&M);
        memset(c,0,sizeof(c));

        for(int i = 0; i < M; i ++){
                scanf("%d %d",&a,&b);
                if(a == 1 || a == N){
                        c[b]++;
                }
                if(b == 1 || b == N){
                        c[a]++;
                }
        }

        for(int i = 1; i <= MAXI-1; i++){
                if(c[i] == 2){
                        puts("POSSIBLE");
                        return 0;
                }
        }
        puts("IMPOSSIBLE");
}
