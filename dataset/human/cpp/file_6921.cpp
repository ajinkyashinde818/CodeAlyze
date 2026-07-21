#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=4e5+5;
typedef long long ll;
int a[maxn],b[maxn];
int cnt[maxn],n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		cnt[b[i]]++;
	}
	for (int i=1;i<=n;i++){
		if (cnt[i]>n){
			cout<<"No"<<endl;
			return 0;
		}
	}
	reverse(b+1,b+n+1);
	int l=1,r=n;
	for (int i=1;i<=n;i++){
		if (a[i]==b[i]){
			if (b[i]!=a[l]&&b[l]!=a[i]){
				swap(b[i],b[l]);
				l++;
				continue;
			}
			else if (b[i]!=a[r]&&b[r]!=a[i]){
				swap(b[r],b[i]);
				r--;
				continue;
			}
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for (int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
}
