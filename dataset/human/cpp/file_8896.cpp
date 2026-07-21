//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

using namespace std;
using ll=long long;

void solve(){
  int num,m;
  cin >> num >> m;
  vector<string> s1(num);
  vector<string> s2(num);
  for(int i=0;i<num;i++)
    cin >> s1[i];
  for(int i=0;i<m;i++)
    cin >> s2[i];
  for(int i=0;i<=num-m;i++)
    for(int j=0;j<=num-m;j++){
      bool b=true;
      for(int k=i;k<i+m;k++)
        for(int l=j;l<j+m;l++)
          b&=s1[k][l]==s2[k-i][l-j];
      if(b){cout << "Yes" << endl;return;}
    }
  cout << "No" << endl;
}

int main(){
  solve();
  return 0;
}
