#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t r,g,b,n,cnt=0;
  cin >> r >> g >> b >> n;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      int k=(n-r*i-g*j)/b;
      if(0<=k && k<=n && r*i+g*j+k*b==n)cnt++;
    }
  }
  cout << cnt << endl;
}
