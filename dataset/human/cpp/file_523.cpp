#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> a(3);
  int n,count=0;
  cin>>a[0]>>a[1]>>a[2]>>n;
  sort(a.begin(),a.end());
  for(int x=0;x*a[0]<=n;x++){
    for(int y=0;x*a[0]+y*a[1]<=n;y++){
        if((n-x*a[0]-y*a[1])%a[2]==0) count++;
    }
  }
  cout<<count<<endl;
}
