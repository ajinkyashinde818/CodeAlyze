#include<iostream>
#include<string>
using namespace std;
struct Radix{
  const char* s;
  int a[128];
  Radix(const char* s="0123456789ABCDEF"):s(s){
    int i;
    for(i=0;s[i];++i)
      a[(int)s[i]]=i;
  }
  string to(long long p,int q){
    int i;
    if(!p)
      return "0";
    char t[64]={};
    for(i=62;p;--i){
      t[i]=s[p%q];
      p/=q;
    }
    return string(t+i+1);
  }
  string to(const string& t,int p,int q){
    return to(to(t,p),q);
  }
  long long to(const string& t,int p){
    int i;
    long long sm=a[(int)t[0]];
    for(i=1;i<(int)t.length();++i)
      sm=sm*p+a[(int)t[i]];
    return sm;
  }
};
int main() {
  int i;
  int n;
  cin >> n;
  Radix r("0123456789abcdef");
  while(n--) {
    string s;
    cin >> s;
    s = r.to(s, 16, 2);
    s = string(32 - s.size(), '0') + s;
    int sm = 0;
    for(i = 0; i < 7; ++i) {
      if(s[s.size() + i - 7 ] == '1')
        sm += 10000000 / (2 << i);
    }
    string t = r.to(sm, 10);
    t = string(7 - t.size(), '0') + t;
    while(t[t.size() - 1] == '0')
      t.erase(t.size() - 1);
    cout << (s[0] == '0' ? "" : "-") << r.to(s.substr(1, 24), 2) << '.' << (sm == 0 ? "0" : t) << endl;
  }
  return 0;
}
