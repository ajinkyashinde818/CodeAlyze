#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=100005;
int n,k=0;
vector <int> v[N];
int main(){
	n=read();
	while (k*(k-1)/2<n)
		k++;
	if (k*(k-1)/2!=n)
		return puts("No"),0;
	int t=0;
	for (int i=1;i<k;i++)
		for (int j=i+1;j<=k;j++){
			v[i].push_back(++t);
			v[j].push_back(t);
		}
	puts("Yes");
	printf("%d\n",k);
	for (int i=1;i<=k;i++){
		printf("%d ",(int)v[i].size());
		for (auto x : v[i])
			printf("%d ",x);
		puts("");
	}
	return 0;
}
