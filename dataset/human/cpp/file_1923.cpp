#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>
#include <deque>
#include <bitset>
#include <cassert>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int dy[]={-1,0,1,0},dx[]={0,1,0,-1};
// adjust problem by problem
const double EPS=1e-8;
const double PI=acos(-1.0);
#ifdef __GNUC__
int popcount(int n){return __builtin_popcount(n);}
int popcount(ll n){return __builtin_popcountll(n);}
#endif
#ifndef __GNUC__
template<class T> int popcount(T n){int cnt=0;while(n){if(n%2)cnt++;n/=2;}return cnt;}
#endif
template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> void PrintSeq(T &a,int sz){for(int i=0;i<sz;i++){cout<<a[i];if(sz==i+1)cout<<endl;else cout<<' ';}}
bool EQ(double a,double b){return abs(a-b)<EPS;}
void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}
vector<string> split(string str,char del){
  vector<string> res;
  for(int i=0,s=0;i<SIZE(str);i++){
    if(str[i]==del){if(i-s!=0)res.push_back(str.substr(s,i-s));s=i+1;}
    else if(i==SIZE(str)-1){res.push_back(str.substr(s));}
  }
  return res;
}

int Q;
string s;

string conv(string s){
  string res;
  for(int i=0;i<8;i++){
    int num=0;
    if(s[i]>='0'&&s[i]<='9'){
      num=s[i]-'0';
    }
    else if(s[i]>='a'){
      num=s[i]-'a'+10;
    }
    string a;
    while(1){
      if(num%2==0)a+='0';
      else a+='1';
      if(a.size()==4)break;
      num/=2;
    }
    reverse(a.begin(),a.end());
    res+=a;
  }
  return res;
}

int main(){
  cin>>Q;
  for(int i=0;i<Q;i++){
    cin>>s;
    s=conv(s);
    //cout<<s<<endl;
    double res=0;
    string is=s.substr(1,24);
    int a=0;
    for(int j=0;j<(int)is.size();j++){
      a=a*2+(is[j]-'0');
    }
    double b=0;
    string fs=s.substr(25,7);
    int fst=-1;
    for(int j=(int)fs.size()-1;j>=0;j--){
      b=(b+(fs[j]-'0'))*0.5;
      if(fst==-1&&fs[j]=='1'){
        fst=j;
      }
      //cout<<b<<endl;
    }
    fst++;
    if(s[0]=='1')cout<<'-';
    cout<<a;
    cout<<".";
    if(fst==0)cout<<"0"<<endl;
    else{
      // stringstream ss;
      // ss<<b;
      //string tmp=ss.str();
      //cout<<tmp<<endl;
      string tmp;
      for(int i=0;i<fst;i++){
        b*=10;
        tmp+=('0'+(int)b);
        b-=(int)b;
      }
      for(int i=0;i<fst;i++)
        cout<<tmp[i];
      cout<<endl;
    }
  }
  
  return 0;
}
