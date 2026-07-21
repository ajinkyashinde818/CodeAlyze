#include<iostream>

using namespace std;

long long int n;
long long int a[100005], b[100005];


long long int dp(long long int m, bool l){
  long long int s[100005][2];
  s[0][0] = 0;
  s[0][1] = -1000000002;
  for(int i = 0; i < m; ++i){
    s[i + 1][0] = max(s[i][0] + a[i], s[i][1] - a[i]);
    s[i + 1][1] = max(s[i][0] - a[i], s[i][1] + a[i]);
  }
  return s[m][0];
  //return a[m];
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  cout << dp(n, 0) << endl;
}
