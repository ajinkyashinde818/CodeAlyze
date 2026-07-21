#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

string getBit(char ch){
  int x = isdigit(ch) ? ch - '0' : ch - 'a' + 10;
  string res = "";
  for(int i = 8; i >= 1; i /= 2){
    if(x & i) res += "1";
    else      res += "0";
  }
  return res;
}

int main(){
  int Q;
  cin >> Q;

  while(Q--){
    string ts;
    cin >> ts;

    string s;

    for(int i = 0; i < ts.size(); i++){
      s += getBit(ts[i]);
    }

    if(s[0] == '1'){
      cout << "-";
    }

    double sum = 0;

    for(int i = 0; i < 24; i++){
      if(s[i + 1] == '0') continue;
      sum += (1 << (23 - i));
    }

    bool flg = true;
    double p = 0.5;

    for(int i = 0; i < 7; i++, p /= 2){
      if(s[25 + i] == '0') continue;
      flg = false;
      sum += p;
    }

    cout << setprecision(30) << sum;
    if(flg){
      cout << ".0";
    }
    cout << endl;
  }
}
