#include <bits/stdc++.h>
using namespace std;
 
string to2(string s) {
  string t="";
  for(int i=0; i<s.size(); i++) {
    int x;
    if(isdigit(s[i])) x=s[i]-'0';
    else x=s[i]-'a'+10;
    string r="";
    while(x) {
      r+='0'+x%2;
      x/=2;
    }
    while(r.size()<4) r=r+'0';
    reverse(r.begin(),r.end());
    t+=r;
  }
  return t;
}
 
string toN(string s) {
  int x=0,y=1;
  for(int i=s.size()-1; i>=0; i--) {
    if(s[i]=='1') x+=y;
    y*=2;
  }
  stringstream ss;
  string t;
  ss << x;
  ss >> t;
  return t;
}
string toD(string s) {
  int x=0,y=5000000;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='1') x+=y;
    y/=2;
  }
  stringstream ss;
  string t;
  ss << x;
  ss >> t;
  while(t.size()<7) t='0'+t;
  int i;
  for(i=t.size()-1; i>=1; i--) {
    if(t[i]!='0') break;
  }
  return t.substr(0,i+1);
}
 
int main() {
  int n;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    s=to2(s);
    if(s[0]=='1') cout << '-';
    cout << toN(s.substr(1,24))+'.'+toD(s.substr(25)) << endl;
  }
  return 0;
}
