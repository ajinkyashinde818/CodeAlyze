#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>

using namespace std;



typedef long long ll;
typedef pair<int,int> P;

const int mod=1e9+7;

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll cnt=0,AbsMin=INT_MAX,Sum=0;
    bool exist0=false;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<0){
            cnt++;
        }else if(a[i]==0){
            exist0=true;
        }
        AbsMin=min(AbsMin,abs(a[i]));
        Sum+=abs(a[i]);
    }  
    if(cnt%2==0){
        cout << Sum << endl;
    }else{
        cout << Sum-2*AbsMin << endl;
    }
    return 0;
}
