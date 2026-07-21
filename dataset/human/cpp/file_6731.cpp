#include<bits/stdc++.h>
using namespace std;
string s;
int a,b,c,d,e;
int main(){
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(isdigit(s[i]))a=a*10+(s[i]-'0'),d*=10;
    else if(s[i]=='.')d++;
    else while(isdigit(s[++i]))b=b*10+(s[i]-'0'),c=c*10+9;
  }
  if(c)a=b+a*c,d=d*c;
  cout<<a/__gcd(a,d)<<'/'<<d/__gcd(a,d)<<endl;
}
