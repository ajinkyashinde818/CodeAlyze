#include<bits/stdc++.h>

template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};

using namespace std;

void solve(){

    int c,k;
    cin>>c;
    vector<int>v(c);
    long long  sum=0;
    for(int i=0;i<c;i++){
        cin>>v[i];  
        sum+=v[i];
    }
    long long  mn=LONG_LONG_MAX;
    long long  res=0;
    for(int i=0;i<c-1;i++){
          res+=v[i];
          sum-=v[i];
          mn=min(mn,abs(res-sum));

    }
    
    cout<<mn;
}

int main(){
       std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
      
       solve(); 
    return 0;
}
