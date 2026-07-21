#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  long long n;
  string s;
  vector<long long> v(26,1);
  cin>>n>>s;
  for(long long i=0;i<n;i++){
    v[s[i]-'a']++;
  }
  long long ans=1;
  for(int i=0;i<26;i++){
    ans*=v[i];
    ans%=1000000007;
  }
  cout<<ans-1<<endl;
  return 0;
}
