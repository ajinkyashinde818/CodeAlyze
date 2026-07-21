#include <bits/stdc++.h>
//Remove below header file if c++ version greater than 14
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define deb(x) cout << #x << " "<< x << endl;
#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)

struct greaterr
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a /gcd(a, b) *b;
}
typedef pair<int,int> pii;
const int mod = 1e9+7;

ll xorr(ll n){

    if(n%4==0)
        return n;

    else if(n%4==1)
        return 1;

    else if(n%4==2)
        return n+1;

    else
        return 0;



}

int main() {

   int n;
   cin>>n;

   int arr[n];
   fo(i,n)
    cin>>arr[i];

   fo(i,n-1){
   if(arr[i]<0){
    arr[i]*=-1;
   arr[i+1]*=-1;
   }
   }

 ll res = 0;

 if(arr[n-1]>=0)
    res = accumulate(arr,arr+n,0LL);
 else{
        arr[n-1]*=-1;
    res = accumulate(arr,arr+n,0LL) - 2* (*min_element(arr,arr+n));
 }
 cout<<res;
























    return 0;

      }
