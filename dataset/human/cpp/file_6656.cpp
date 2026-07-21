#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

char ca[200005];

int main(){
	int n;
	int i,j,k;
	LL a,b,c;
	LL s=0;
	bool flag=true,t=false;
	cin>>n;
	n*=2;
	cin>>ca;
	if(ca[0]=='W')flag=false;
	a=1;
	s=1;
	for(i=1;i<n;i++){
		if(!t){
			if(ca[i]==ca[i-1])s*=a--,t=true;
			else a++,t=false;
		}else{
			if(ca[i]!=ca[i-1])s*=a--,t=true;
			else a++,t=false;
		}
		if(a<0)flag=false;
		if(s>=MAX)s%=MAX;
	}
	if(a!=0)flag=false;
	if(!flag)s=0;
	for(a=1;a<=n/2;a++){
		s*=a;
		if(s>=MAX)s%=MAX;
	}
	cout<<s<<endl;
}
