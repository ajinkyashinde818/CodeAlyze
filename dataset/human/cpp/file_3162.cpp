#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n,rieki,answer;
  answer=0;
	cin >> n;
  vector<ll> dp0(n);
  vector<ll> dp1(n);
  vector<ll> vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
  }
    for(int i=0;i<n;i++){
      if(i==0){
        dp0.at(0)=vec.at(0);
        dp1.at(0)=-1*vec.at(0);
      }
      else{
        dp0.at(i)=max(dp0.at(i-1)+vec.at(i),dp1.at(i-1)-vec.at(i));
        dp1.at(i)=max(dp0.at(i-1)-vec.at(i),dp1.at(i-1)+vec.at(i));
      }
    }
  cout<<dp0.at(n-1)<<endl;
}
