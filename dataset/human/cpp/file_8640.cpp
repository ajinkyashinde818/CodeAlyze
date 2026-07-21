#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  cin >> n >>m;
  vector<string> N(n),M(m);
  for(int i = 0;i<n;i++){
    cin >> N.at(i);
  }
  for(int i = 0;i<m;i++){
    cin >>M.at(i);
  }
  vector<string> L(m);
  for(int i= 0;i+m<=n;i++){
    for(int j = 0;j+m<=n;j++){
      for(int k = 0;k<m;k++){
        L.at(k) = N.at(k+i).substr(j,m);
      }
      if(L == M){
      	cout << "Yes";
      	return 0;
      }
    }
  }
  cout<<"No";
}
