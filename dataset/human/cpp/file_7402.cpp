#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
double PI = 3.14159265358979;

int main(){
 ll N;
 cin >> N;
 ll ans = 987654323456787654;
 vector<ll> A(N);
 vector<ll> L(N,0);
 ll sum = 0;
 for(ll i = 0;i < N;i++){
     cin >> A[i];
     sum += A[i];
     if(i != N-1){
        L[i+1] = L[i] + A[i];
     }
 }
 if(N == 2){
     cout << abs(A[0] - A[1]) << endl;
     return 0;
 }
 for(ll i = 1;i < N;i++){
     ll c = abs(sum - L[i] - L[i]);
     ans = min(ans,c);
 }
 cout << ans << endl;
}
