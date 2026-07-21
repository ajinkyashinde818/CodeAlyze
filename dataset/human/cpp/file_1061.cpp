#include <bits/stdc++.h>
using namespace std;
int n,r,g,b,ans;
int main(){
	//freopen("input.txt","r",stdin);
	cin >> r >> g >> b >> n;
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= n;j++){
			int temp = i*r + j*g;
			if(temp > n)break;
			temp = n - temp;
			if(temp%b == 0)ans++;
		}
	printf("%d\n",ans);
}
