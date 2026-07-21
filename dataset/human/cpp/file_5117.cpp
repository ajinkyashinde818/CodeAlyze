#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

  int k,r;cin>>k>>r;

  if(k>=10){
    cout<<r<<endl;
  }else{
    cout<<r+100*(10-k)<<endl;
  }
  
  return 0;
}
