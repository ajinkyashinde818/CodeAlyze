#include <bits/stdc++.h>
#include <math.h>
using namespace std;

double f(double x){
  if(x < 0){x *= (-1);}
  return x;
}

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  double sum = 0;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    sum += v[i];
  }

  double ave = sum / 2;
  double sum1 = v[0];
  double res = f(ave - v[0]);
  double memo;
  if(n == 2){cout << fixed << setprecision(0); cout << f(v[0] - v[1]) << endl;}
  else{
  for(int i = 1; i < n -1; i++){
    sum1 += v[i];
    if(f(sum1 - ave) < res){res = f(sum1 - ave); memo = sum1;}
  }
  cout << fixed << setprecision(0);
  //cout << memo << endl;
  //cout << res << endl;
  cout << f(sum - memo * 2)  << endl;
  }
}
