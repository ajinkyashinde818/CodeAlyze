#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = int(1e5) + 7;

void init(){

}

void solve(){
    int n; scanf("%d", &n);
    int c = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        if(a <= 0){
            c++;
            v.push_back(-a);
        }
        else v.push_back(a);
    }
    ll sum = 0;
    for(auto i : v)
        sum += i;
    if(c%2 == 1)
        sum -= 2*(*min_element(v.begin(), v.end()));
    printf("%lld\n", sum);
}

const bool mtc = false;

int main(){
    int t;
    if(mtc){
        scanf("%d", &t);
        while(t--) solve();
    }
    else solve();
}
