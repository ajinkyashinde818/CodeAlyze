#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0;
    int n, a;
    scanf("%d", &n);
    int mn = 1e9;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        if(a > 0){
            ans += a;
            mn = min(mn, a);
        }
        else pq.push(-a);
    }
    if(pq.size()%2 == 0){
        while(!pq.empty()){
            int u = pq.top();
            pq.pop();
            ans += u;
        }
    }
    else{
        int last = 0;
        while(!pq.empty()){
            int u = pq.top();
            pq.pop();
            ans += u;
            last = u;
        }
        ans -= last;
        ans = max(ans+last-2*mn, ans-last);
    }

    printf("%lld\n", ans);
}
