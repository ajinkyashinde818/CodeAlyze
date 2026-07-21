#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const ll MX = 200005;
ll N, A[MX], B[MX];

bool cmp(ll&a, ll&b){
    return a > b;
}

bool solve(){
    sort(B, B+N, cmp);
    int b = MX, e = -1;
    for(int i=0; i<N; i++){
        if(A[i] == B[i]){
            b = min(b, i);
            e = max(e, i);
        }
    }
    if(e < 0) return true;

    int t = A[b];
    int ab = MX, ae = -1, bb = MX, be = -1;
    for(int i=0; i<N; i++){
        if(A[i] == t){
            ab = min(ab, i);
            ae = max(ae, i);
        }
        if(B[i] == t){
            bb = min(bb, i);
            be = max(be, i);
        }
    }
    int b1 = min(ab, bb), e1 = max(ae, be);
    int sn = (b1 + N - e1 - 1);
    if(sn < e - b + 1) return false;

    int j = b;
    for(int i=0; i<b1 && j<=e; i++, j++){
        swap(B[i], B[j]);
    }   

    for(int i=e1+1; i<N && j<=e; i++, j++){
        swap(B[i], B[j]);
    }
    return true;

}

int main(){
   // freopen("in.txt", "r", stdin);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    for(int i=0; i<N; i++){
        cin>>B[i];
    }
    if(solve()){
        cout<<"Yes"<<endl;
        for(int i=0; i<N; i++){
            cout<<B[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
