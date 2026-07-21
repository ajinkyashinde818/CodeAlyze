#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  long long n;
  cin>> n>> s;
  
  vector<long long> v(26);
  for(long long i=0;i<n;i++){
       v.at(s.at(i)-'a')++;
  }
  long long  r=1;
  long long m=1000000007 ;
  for(long long i=0;i<26;i++){
     if(v.at(i)!=0) r*=(v.at(i)+1);
     r = r%m;
  }
  
  long long z=(r-1)%m;
  cout <<z<< endl;
}
