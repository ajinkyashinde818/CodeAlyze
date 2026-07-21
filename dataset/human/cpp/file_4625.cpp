#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
//unordered_map<int,int> mapp;
int n,r;
int read() {
	char ch = getchar();
	int x = 0, f = 1;
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
	while (ch >= '0' && ch <= '9') x = x*10 + ch - 48, ch = getchar();
	return x * f;
}
int main() {
    cin>>n>>r;
    if(n>=10) cout<<r;
    else cout<<r+100*(10-n);
	return 0;
}
