#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

  int r,n;cin>>n>>r;

  if(n>=10){
    cout<<r<<endl;
  }else{
    cout<<r+100*(10-n)<<endl;
  }

  
  return 0;
}
