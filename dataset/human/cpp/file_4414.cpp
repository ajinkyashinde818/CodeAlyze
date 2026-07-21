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
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

int t[100005][2];
vector<int> v1,v2;
map<int,int> m1;
vector<int> path[100005];
bool used[100005];

void check(int a){
	if(used[a])return;
	used[a]=true;
	for(auto to:path[a])check(to);
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int p,q;
	int s=0;
	cin>>n;
	p=0,q=0;
	for(i=0;i<n;i++){
		cin>>a;
		t[i][0]=a;
		v1.push_back(a);
		p^=a;
	}
	for(i=0;i<n;i++){
		cin>>a;
		t[i][1]=a;
		v2.push_back(a);
		q^=a;
	}
	v1.push_back(p),v2.push_back(q);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(i=0;i<v1.size();i++){
		if(v1[i]!=v2[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	if(b==c)s=n;
	else s=n-1;

	for(c=0,i=0;i<n;i++){
		a=t[i][0],b=t[i][1];
		if(a==b){
			s--;
			continue;
		}
		if(m1.find(a)==m1.end())m1[a]=c++;
		if(m1.find(b)==m1.end())m1[b]=c++;
		a=m1[a],b=m1[b];
		path[a].push_back(b);
		path[b].push_back(a);
	}
	for(i=0;i<c;i++){
		if(used[i])continue;
		check(i);
		s++;
	}
	if(m1.find(p)!=m1.end())s--;
	cout<<s<<endl;
}
