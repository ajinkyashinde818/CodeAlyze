#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long lli;

const lli M = 10000000000000LL;

lli digits(lli x){
  lli res = 0;
  if(!x) return 1;
  while(x){
    res++;
    x /= 10;
  }
  return res;
}

lli calc1(string s){
  lli res = 0;
  for(int i=0;i<s.size();i++){
    res *= 2;
    res += s[i] - '0';
  }
  return res;
}

string calc2(string s){
  lli sum = 0;
  lli m = M;
  for(int i=0;i<s.size();i++){
    m /= 2;
    if(s[i] == '1') sum += m;
  }
  lli tmp = 13 - digits(sum);
  while(sum && sum % 10 == 0) sum /= 10;
  string res;
  if(!sum) return "0";
  while(sum){
    res += sum % 10 + '0';
    sum /= 10;
  }
  if(tmp != -1) for(int i=0;i<tmp;i++) res += '0';
  reverse(res.begin(), res.end());
  return res;
}

string calc3(lli x){
  string res;
  while(x >= 2){
    res += '0' + x % 2;
    x /= 2;
  }
  if(x) res += '0' + x;
  int size = 4 - res.size();
  for(int i=0;i<size;i++) res += '0';
  reverse(res.begin(), res.end());
  return res;
}

string conv(string& in){
  string res;
  for(int i=0;i<in.size();i++){
    lli num;
    if('0' <= in[i] && in[i] <= '9') num = in[i] - '0';
    else num = in[i] - 'a' + 10;
    res += calc3(num);
  }
  return res;
}

main(){
  int T;
  cin >> T;
  while(T--){
    string in;
    cin >> in;
    string data = conv(in);
    if(data[0] == '1') cout << "-";
    cout << calc1(data.substr(1, 24)) << "." << calc2(data.substr(25)) << endl;
  }
}
