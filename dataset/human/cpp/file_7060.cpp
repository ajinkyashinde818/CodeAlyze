#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const char sp = ' ';

using namespace boost::multiprecision;
using namespace std;

int main(void){
    ll N;
    vector<ll> A, Bho, B;
    ll a, b;
    cin>>N;
    rep(i, N){
        cin>>a;
        A.push_back(a);
    }
    rep(i, N){
        cin>>b;
        Bho.push_back(b);
    }
    rep(i, N){
        B.push_back(Bho[N-1-i]);
    }
    ll eq=0;
    ll count1=0;
    bool ok=false;
    ll senpo;
    rep(i, N){
        if(A[i]==B[i]){
            
            eq=A[i], count1++;
            if(!ok){
                senpo=i;
                ok=true;
            }
        }
    }
    ll count2=0;
    ok=false;
    ll sento;
    rep(i, N){
        if(A[i]==eq || B[i]==eq){
            count2++;
            if(!ok){
                ok=true;
                sento=i;
            }
        }
    }
    
    if(count1>N-count2){
        cout<<"No"<<endl;
        return 0;
    }
   
    cout<<"Yes"<<endl;
    ll dum=0;
    while(dum<sento && dum<count1){
        swap(B[dum], B[senpo+dum]);
        dum++;
        
    }
    ll intr=0;
    sento+=count2;
    while(dum<count1){
        swap(B[sento+intr], B[senpo+dum]);
        intr++;
        dum++;
    }
    rep(i, N){
        cout<<B[i];
        if(i==N-1) cout<<endl;
        else cout<<sp;
    }
    return 0;
}
