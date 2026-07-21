#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>N;
  cin>>S;
  map<char,int>mp;
  long long cnt=1;
  for(int i=0;i<N;i++){
    mp[S.at(i)]++;
  }
  for(char c='a';c<='z';c++){
    if(mp[c]){
      cnt=(cnt*(mp[c]+1))%1000000007;
    }
  }
  cout<<cnt-1<<endl;
  return 0;
}
