#include<iostream>
#include<algorithm>
#include<sstream>

using namespace std;

string binary[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000",
		   "1001","1010","1011","1100","1101","1110","1111"};
string ss = "0123456789abcdef";

string toB(char c){
  for(int i = 0; i < ss.length(); i++){
    if(ss[i] == c) return binary[i];
  }
  return "error";
}

string make(string s){
  string ret = "";

  for(int i = 0; i < s.length(); i++){
    ret += toB(s[i]);
  }
  return ret;
}

string toInt(string s){
  int ans = 0;
  int base = 1;
  
  for(int i = s.length()-1; i >= 0; i--){
    if(s[i] == '1') ans+=base;
    base*=2;
  }
  ostringstream oss;
  oss << ans;
  return oss.str();
}

string toDou(string s){

  double tmp = 0;
  double base = 0.5;

  for(int i = 0; i < s.length(); i++){
     if(s[i] == '1') tmp+=base;
     base/=2;
  }
  
  string anss = "";

  if(tmp == 0) return "0";

  
  while(tmp){
    tmp *= 10;
    int now = (int)tmp;
    anss += ((int)tmp)+'0';
    tmp -= now;
  }
  
  return anss;
}

void solve(string s){
  char sign = s[0];
  string integer = s.substr(1,24);
  string decimal = s.substr(25);
 
  if(sign == '1') cout << "-";
  cout << toInt(integer) << "." << toDou(decimal) << endl;
}

int main(){

  int T;
  cin >> T;
  while(T--){
    string in;
    cin >> in;
    string s = make(in);
    solve(s);
  }
  return 0;
}
