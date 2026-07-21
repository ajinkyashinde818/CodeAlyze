#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
int n;
int a[N], b[N];
int ca[N], cb[N];
signed main(){
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read(), ca[a[i]]++;
	for(int i = 1; i <= n; i++) b[i] = read(), cb[b[i]]++;
	for(int i = 1; i <= n; i++) if(ca[i] + cb[i] > n) return printf("No\n"), 0;
	reverse(b + 1, b + n + 1);
	vector<int> t;
	int cnt = 0, val = 0, len = 0;
	for(int i = 1; i <= n; i++)
	{
		if(b[i] == a[i])
		{
			cnt++;
			val = b[i];
			t.push_back(i);
		}
	}
  	// t has at most one unique element
	len = cnt;
	vector<int> s;
	for(int i = 1; i <= n; i++)
	{
	 if(a[i] == b[i]) continue;
	 if(cnt == 0) break;
	 if(a[i] != val && b[i] != val)
	 {
	 	s.push_back(i);
	 	cnt--;
       	if(cnt)
			val = b[t[cnt - 1]];
	 }		
	}
	for(int i = 0; i < len; i++)
	{
		swap(b[s[i]], b[t[i]]);
	}
	printf("Yes\n");
	for(int i = 1; i <= n; i++) printf("%d ", b[i]);
	printf("\n");
	return 0;
}
