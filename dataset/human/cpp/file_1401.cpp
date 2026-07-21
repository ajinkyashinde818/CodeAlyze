#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int>a[1200000];
int n,m,tot;
int cal(int x){
	for(int i=1;i<=x;i++){
		for(int j=i+1;j<=x;j++){
			tot++;
			a[i].push_back(tot);
			a[j].push_back(tot);
		}
	}
	printf("Yes\n");
	printf("%d\n",x);
	for(int i=1;i<=x;i++){
		printf("%d ",a[i].size());
		for(int j=0;j<a[i].size();j++)printf("%d ",a[i][j]);
		printf("\n");
	}
	exit(0);
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		m+=i;
		if(m==n)cal(i+1);
		if(m>n)break;
	}
	printf("No\n");
}
