#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int n,m;
vector<int> vec[maxn];

int main(){
	cin>>n;
	while(m*(m-1)/2<n)
		++m;
	if(m*(m-1)/2>n){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1,k=0;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			vec[i].push_back(++k),vec[j].push_back(k);
	printf("%d\n",m);
	for(int i=1;i<=m;++i){
		printf("%d ",m-1);
		for(int j=0;j<vec[i].size();++j)
			printf("%d ",vec[i][j]);
		puts("");
	}
	return 0;
}
