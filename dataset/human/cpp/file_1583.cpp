#include<bits/stdc++.h>
int n,m,i,j,x;
std::vector<int>v[999];
int main(){
	scanf("%d",&n);
	m=(1+sqrt(1+8*n))/2;if(m*(m-1)/2!=n)return puts("No"),0;
	for(i=1;i<m;++i)for(j=i+1;j<=m;++j)++x,v[i].push_back(x),v[j].push_back(x);
	printf("Yes\n%d\n",m);
	for(i=1;i<=m;++i)for(int x:v[printf("%d ",m-1),i])printf("%d%c",x,x==v[i].back()?'\n':' ');
	return 0;
}
