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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *a,int n,char middle=' '){
	for(int i=0;i<n;i++)printf("%d%c",a[i],(i!=n-1?middle:'\n'));
}
void array_show(LL *a,int n,char middle=' '){
	for(int i=0;i<n;i++)printf("%lld%c",a[i],(i!=n-1?middle:'\n'));
}

void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

vector<int> v1[2];
char ca[100005];
LL s=0;

void check(int dis,int a,LL m){
	if(a==-1)return;
	if(v1[0][a]==-1 && v1[1][a]==-1)return;
	if(v1[0][a]==-1 || v1[1][a]==-1){
		LL b=m-dis;
		int i=0;
		for(;(b&(1<<i))==0;i++);
		s^=(1<<i);
	}
	check(dis+1,v1[0][a],m);
	check(dis+1,v1[1][a],m);
}

int main(){
	LL n,m;
	int a,b,c;
	int i,j,k;
	cin>>n>>m;
	v1[0].push_back(-1),v1[1].push_back(-1);
	for(i=0;i<n;i++){
		cin>>ca;
		for(j=0,a=0;j<strlen(ca);j++){
			if(ca[j]=='0')k=0;
			else k=1;
			if(v1[k][a]==-1){
				v1[k][a]=v1[0].size();
				v1[0].push_back(-1),v1[1].push_back(-1);
			}
			a=v1[k][a];
		}
	}
	check(0,0,m);
	cout<<(s!=0?"Alice":"Bob")<<endl;
	return 0;
}
