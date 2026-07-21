#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef unsigned int ui;

ui trans(string s){
  ui res = 0, k = 1, tmp;
  for(int i=7;i>=0;i--){
    if('0'<=s[i] && s[i]<='9')tmp = s[i]-'0';
    else tmp = s[i]-'a' + 10;
    res += k*tmp; k*=16;
  }
  return res;
}

int main(){
  int q; string s; ui u;
  cin >> q;
  for(int x=0;x<q;x++){
    cin >> s;
    u = trans(s);
    double ans = 0,k = 1.0/(1<<7);
    for(int i=0;i<31;i++){
      ans += k * ((u>>i)&1U); k *= 2;
    }
    if(((u>>31)&1U))ans *= -1;

    cout.precision(20);
    cout << ans;
    if(!(u&((1U<<7)-1)))cout << ".0";
    cout << endl;
  }
}
