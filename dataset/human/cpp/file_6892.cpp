#include<bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+6;
int n, a[maxn], b[maxn];
int l=-1, r=-2, c;

int main(){
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<n;i++) cin >> b[i];
	reverse(b,b+n);
	for (int i=0;i<n;i++){
		if (a[i]==b[i]){
			if (l==-1) l=i;
			r=i;
			c=a[i];
		}
	}
	int idx=0;
	for (int i=l;i<=r;i++){
		while (idx<n && (b[idx]==c || a[idx]==c)) idx++;
		if (idx==n) break;
		swap(b[i],b[idx]);
		idx++;
	}
	for (int i=0;i<n;i++){
		if (a[i]==b[i]){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for (int i=0;i<n;i++) cout << b[i] << " ";
	cout << "\n";
}
