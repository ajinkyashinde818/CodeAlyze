#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
typedef long long ll;
ll nOO  = -1e15 ;
int A[N],n,x,y,z,cnt;
ll mem[N][2];
ll solve(int idx,bool nega){
    if(idx==n-1) return (nega)? -A[idx] : A[idx];
    if(idx==n) return 0;
    if(mem[idx][nega]!=-1) return mem[idx][nega];
    ll v=A[idx];
    if(nega) v*=-1;
    ll op1 = v+ solve(idx+1,0);
    ll op2 = -v  + solve(idx+1,1);
    return mem[idx][nega] = max(op1,op2);

}
int main(){
    memset(mem,-1,sizeof mem);
    scanf("%d",&n);
    for( int i = 0 ; i < n; ++i )
        scanf("%d",A+i);
    printf("%lld\n",solve(0,0));
    return 0;
}
