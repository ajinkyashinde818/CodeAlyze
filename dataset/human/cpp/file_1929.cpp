#include<bits/stdc++.h>
using namespace std;
int To10(char c);
main(){
  long long n;
  string s;
  string s2;
  string to2[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
  cin>>n;
  for(int i=0;i<n;i++){
    double ans=0;
    cin>>s;
    s2="";
    for(int i=0;i<s.size();i++){
      s2+=to2[To10(s[i])];
    }
    long long plus=1;
    for(int i=24;i>=1;i--){
      if(s2[i]=='1'){
	ans+=plus;
      }
      plus*=2;
    }
    double pl=0.5;
    for(int i=25;i<=31;i++){
      if(s2[i]=='1'){
	ans+=pl;
      }
      pl/=2;
    }
    if(s2[0]=='1'){
      printf("-");
    }
    char buff[128];
    sprintf(buff,"%.12lf",ans);
    bool syosuten=false;
    long long last=-1;
    long long point=0;
    for(int i=0;i<strlen(buff);i++){
      if(syosuten&&buff[i]!='0'){
	last=i;
      }
      if(!syosuten) cout<<buff[i];
      if(buff[i]=='.'){
	point=i;
	syosuten=true;
      }
    }
    if(last==-1){
      printf("0\n");
    }
    else{
      for(int i=point+1;i<=last;i++){
	cout<<buff[i];
      }
      cout<<endl;
    }
  }
}
int To10(char c){
  if(c>='0'&&c<='9'){
    return c-'0';
  }
  else{
    return c-'a'+10;
  }
}
