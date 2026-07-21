#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

typedef long long lli;

map<char,string> conv;

void init() {
  conv['0'] = "0000";
  conv['1'] = "0001";
  conv['2'] = "0010";
  conv['3'] = "0011";
  conv['4'] = "0100";
  conv['5'] = "0101";
  conv['6'] = "0110";
  conv['7'] = "0111";
  conv['8'] = "1000";
  conv['9'] = "1001";
  conv['a'] = "1010";
  conv['b'] = "1011";
  conv['c'] = "1100";
  conv['d'] = "1101";
  conv['e'] = "1110";
  conv['f'] = "1111";
}

int main() {
  init();
  int Tc;
  cin >> Tc;
  while(Tc--) {
    string line;
    cin >> line;
    string bit;
    for(int i = 0; i < line.size(); ++i) bit += conv[line[i]];
    reverse(bit.begin(), bit.end());
    if(bit[31] == '1') cout << '-';
    lli inte = 0;
    for(int i = 7; i <= 30; ++i) {
      if(bit[i] == '1') inte |= 1LL<<(i-7);
    }
    cout << inte;
    cout << '.';
    lli f = 0;
    for(int i = 0; i < 7; ++i) {
      if(bit[i] == '1') {
        f +=  (lli)( pow(0.5, 7-i) * pow(10.0, 7.0) );
      }
    }
    if(f == 0) {
      cout << 0 << endl;
      continue;
    }
    char buff[100];
    sprintf(buff, "%07lld", f);
    string s(buff);
    int k;
    for(k = s.size()-1; k >= 0 && s[k] == '0'; --k);
    cout << s.substr(0, k+1) << endl;
  }
  return 0;
}
