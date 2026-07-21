#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll cnt=0;
ll a=0,b=0,c=0;
ll as=0,bs=0,cs=0;

int main(){
  cin>>s;
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='.')cnt=0;
    if(s[i]=='.'||s[i]=='('||s[i]==')')continue;
    a=a*10+(s[i]-'0');
    as++;
    cnt++;
  }
  c=a;
  cs=as;
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='(')b=0,bs=0;
    if(s[i]=='.'||s[i]=='('||s[i]==')')continue;
    b=b*10+(s[i]-'0');
    bs++;
  }

  if( (int)s.find('.') == -1 ){
    cout<<s<<"/1"<<endl;
    return 0;
  }
  
  if( (int)s.find('(') != -1 ){
    
    
    for(int i=0;i<bs;i++){
      a*=10;
      as++;
    }
    a+=b;


    ll A=1,C=1;
    as=cnt+bs;
    cs=cnt;
    for(int i=0;i<as;i++)A*=10;
    for(int i=0;i<cs;i++)C*=10;
    //    cout<<a<<' '<<c<<endl;
    //    cout<<as<<' '<<cs<<endl;
    //    cout<<A<<' '<<C<<endl;
    ll X=a-c,Y=A-C,Z=__gcd(X,Y);
    cout<<X/Z<<'/'<<Y/Z<<endl;
  }else{
    ll X=a;
    ll Y=1;
    for(int i=0;i<cnt;i++)Y*=10;

    ll Z=__gcd(X,Y);
    cout<<X/Z<<'/'<<Y/Z<<endl;
  }
  return 0;
}
