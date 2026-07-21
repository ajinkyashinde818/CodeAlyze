#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> A(N);
  bool flag=false;
  int count=0;
  int64_t ans=0;
  int64_t a;
  for(int i=0;i<N;i++){
    cin >> a;
    if(a==0){
      flag=true;
    }
    if(a<0){
      count++;
    }
    A.at(i)=abs(a);
  }
  if(flag){
    for(int i=0;i<N;i++){
      ans+=A.at(i);
    }
    cout << ans << endl;
  }else{
    if(count%2==0){
      for(int i=0;i<N;i++){
        ans+=A.at(i);
      }
      cout << ans << endl;
    }else{
      sort(A.begin(),A.end());
      ans-=A.at(0);
      for(int i=1;i<N;i++){
        ans+=A.at(i);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
