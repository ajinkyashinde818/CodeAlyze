#include <bits/stdc++.h>
using namespace std;

int main(){
  long N,cnt=0,ans=0;
  cin >> N;
  vector<long> vec(N);
  bool zero=0;
  for(int i=0;i<N;i++){
    cin >> vec[i];
    if(vec[i]==0)
      zero=1;
    if(vec[i]<0)
      cnt++;
  }
  if(zero||cnt%2==0){
    for(int j=0;j<N;j++){
      if(vec[j]<0)
        ans-=vec[j];
      else
        ans+=vec[j];
    }
  }
  else{
    for(int k=0;k<N;k++){
      if(vec[k]<0)
        vec[k]*=-1;
    }
    sort(vec.begin(),vec.end());
    ans-=vec[0];
    for(int l=1;l<N;l++)
      ans+=vec[l];
  }
  cout << ans << endl;
}
