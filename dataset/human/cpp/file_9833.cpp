#include<bits/stdc++.h>

int cnt[108];

using namespace std;

int main(){

  int n;

  string s;

  cin>>n>>s;

  for(char c:s){

   cnt[c]++;

  }

  long long ans = 1;

  long long mof=1e9+7;

  for(char c = 'a';c<='z';c++){

    ans*=cnt[c]+1;

    ans%= mof;

  }

  cout<<(ans-1+mof)%mof<<endl;

}
