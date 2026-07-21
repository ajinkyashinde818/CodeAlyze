#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn=200050;
vector<int> v[maxn];
int a[maxn],b[maxn];
int sum1[maxn],sum2[maxn];
bool mark[maxn];
int n;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum1[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sum2[b[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(sum1[i]+sum2[i]>n){
			printf("No\n");return;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			v[a[i]].push_back(i);
		}
	}
	int l=1,r=n;
	while(1){
		while(l<=n&&!v[l].size())	l++;
		while(r>=1&&!v[r].size())	r--;
		if(l>n||r<1||l==r)	break;
		int pos1=v[l].back();
		int pos2=v[r].back();
		v[l].pop_back();
		v[r].pop_back();
		swap(b[pos1],b[pos2]);
	}
	if(l==r){
		for(int i=1;i<=n;i++){
			if(a[i]!=l&&b[i]!=l){
				int pos=v[l].back();
				v[l].pop_back();
				swap(b[pos],b[i]);
				if(!v[l].size())	break;
			}
		}
	}
	if(v[l].size()){
		printf("No\n");return;
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++)	printf("%d ",b[i]);
	printf("\n");
}
int main(){
	solve();
	return 0;
}
