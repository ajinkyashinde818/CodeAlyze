#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

typedef long long ll;

int MOD=1000000007;

int main()
{
  ll N,R,ans=0;
  cin >> N >> R;
  if(N<10) ans=R+(100*(10-N));
  else ans= R;
  cout << ans << endl;
}
