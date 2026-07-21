#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  string s;
  cin>>s;
vector<int64_t>A(26,1);
  for(int i=0;i<N;i++){
  char x=s.at(i);
    int y=x-'a';
    A.at(y)++;
  
  }int64_t ans=1;
  for(int i=0;i<26;i++){
  ans=(ans*A.at(i))%1000000007;
  } ans--; cout<<ans<<endl;
   return 0;
}
