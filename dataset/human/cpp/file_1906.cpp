#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

map<char, string> t;

void init(){
  t['0'] = "0000";
  t['1'] = "0001";
  t['2'] = "0010";
  t['3'] = "0011";
  t['4'] = "0100";
  t['5'] = "0101";
  t['6'] = "0110";
  t['7'] = "0111";
  t['8'] = "1000";
  t['9'] = "1001";
  t['a'] = "1010";
  t['b'] = "1011";
  t['c'] = "1100";
  t['d'] = "1101";
  t['e'] = "1110";
  t['f'] = "1111";
}

string toString(long double d){
  ostringstream oss;
  oss << setprecision(32) << d;
  return oss.str();
}
  

string toBinary(string s){
  string ret = "";
  for(int i = 0 ; i < s.size() ; i++){
    ret += t[s[i]];
  }
  return ret;
}

long double calcDecimal(string s){
  long double ret = 0.0f;
  for(int i = 25 ; i < 32 ; i++){
    if(s[i] == '1') ret += pow(0.5, i-24);
  }
  return ret;
}

long double calcInte(string s){
  long double ret = 0.0f;
  for(int i = 1 ; i < 25 ; i++){
    if(s[i] == '1') ret += pow(2.0, 24-i);
  }
  return ret;
}

string hitPoint(string s){
  bool ispoint = false;
  for(int i = 0 ; i < s.size() ; i++){
    if(s[i] == '.') ispoint = true;
  }
  
  if(!ispoint) s += ".0";
  return s;
}

string eraseZero(string s){
  if(s.size() == 1) return s;
  string ret;
  for(int i = s.size()-1 ; i >= 0 ; i--){
    if(s[i] == '.') return s;
    if(s[i] != '0') return s.substr(0, i+1);
  }
}
  
int main(){
  init();
  int n;
  cin >> n;
  string sixt;
  while(n--){
    cin >> sixt;
    string s = toBinary(sixt);
    long double inte = calcInte(s);
    long double decimal = calcDecimal(s);
    
    //cout << setprecision(16) << "inte = " << inte << endl << "decimal = " << decimal << endl;
    
    long double ans = inte + decimal;
    string Ans;
    Ans = toString(ans);
    string answer = Ans;
    answer = hitPoint(answer);
    if(s[0] == '1') cout << '-';
    cout << answer << endl;
    /*
    cout << "Ans = " << Ans << endl;
    string ANS = eraseZero(Ans);
    //cout << "ANS = " << ANS << endl;
    ANS = hitPoint(ANS);
    if(s[0] == '1') cout << '-';
    cout << ANS << endl;
    */
  }
  return 0;
}
