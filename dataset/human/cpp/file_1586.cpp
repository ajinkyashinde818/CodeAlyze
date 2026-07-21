#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;

int qw[N],cnt,q[N],n;
vector<int>in[500];

int main(){
	int i=1,j;
	cin>>n;
	for(i=1;;++i){
		qw[i]=qw[i-1]+i;
		if(qw[i]>=n) break;
	}
	if(qw[i]!=n){
		puts("No");
		return 0;
	}
	cnt=i;
	puts("Yes");
	cout<<cnt+1<<endl;
	int cot=0;
	for(i=1;i<=cnt;++i)
	 for(j=i+1;j<=cnt+1;++j){
	 	++cot;
	    in[i].push_back(cot);
	    in[j].push_back(cot);
	 }
	for(i=1;i<=cnt+1;++i){
		printf("%d",cnt);
		for(j=0;j<cnt;++j)
		 printf(" %d",in[i][j]);
		 puts("");
	}
	return 0;
}
