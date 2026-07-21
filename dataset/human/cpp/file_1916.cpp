#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n--){
    int o=0;
    double d=0.0,w=2147483648.0;
    for(int i=0;i<8;i++)w/=2;
    string s;
    cin>>s;
    for(int i=0;i<8;i++){
      int p;
      if(s[i]>='0'&&s[i]<='9')p=s[i]-'0';
      else p=s[i]-'a'+10;
      int ss[4]={};
      for(int j=3;j>=0;j--)ss[j]=(p>>j)&1;
      for(int j=3;j>=0;j--){//cout<<w<<endl;
	if(!i&&j==3){if(ss[j])o++;}
	else{
	  if(ss[j])d+=w;
	  w/=2.0;
	  if(w==0)w=0.5;//cout<<w<<endl;
	}
      }
    }
    if(o)cout<<'-';
    if(d-(long int)d){
      printf("%.99g\n",d);
    }
    else{
      printf("%ld",(long int)d);cout<<".0"<<endl;
    }
   }
}
