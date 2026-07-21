#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath> 
typedef long long ll;
using namespace std;
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline int rd(){
	int res=0,sign=1;char ch;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')sign=-1;res=res*10+ch-48;
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-48;
	return res*sign;
}
int n,r;
int main(){
	cin>>n>>r;
	if(n<10)cout<<100*(10-n)+r<<endl;
	else cout<<r<<endl;
	return 0;
}
