#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,A,minus=0,ans=0,Min=10e9;
  bool zero=false;
  cin >>N;
  
  for(int i=0; i<N; i++){
    cin >> A;
    if(A<0) minus++;
    else if(A==0)zero=true;
    if(abs(A)<Min)Min=abs(A);
    ans+=abs(A);
  }
  
  if(minus%2==1&&zero==false)ans-=Min*2;
  
  cout<< ans<<endl;
}
