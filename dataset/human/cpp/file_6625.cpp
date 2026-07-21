#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;


int main ()
{
  prep();
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cur = 1;
  if (s[0] != 'B'){
      cout << 0;
      return 0;
  }
  long long res = 1;
  bool endnow = false;
  for (int i=1; i<2*n; i++){
      if (cur == n*2-i){
          endnow = true;
      }
      
      if (s[i] == 'B'){
          if (cur%2 == 1){
              res *= cur;
              res %= mod;
              cur--;
          }else{
              // increase or decrease
              if (endnow){
                  cout << 0;
                  return 0;
              }else{
                  cur++;
              }
          }
      }else{
          if (cur%2 == 1){
              if (endnow){
                  cout << 0;
                  return 0;
              }else{
                  cur++;
              }
          }else{
              res *= cur;
              res %= mod;
              cur--;
          }
      }
      //cout << cur << endl;
  }
  if (cur != 0){
      cout << 0;
      return 0;
  }
  for (int i=2; i<=n; i++){
      res *= i;
      res %= mod;
  }
  cout << res;
  return 0; 
}
