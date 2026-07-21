#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename _tp> inline void read(_tp&x){
	char c11=getchar(),ob=0;x=0;
	while(c11!='-'&&!isdigit(c11))c11=getchar();if(c11=='-')ob=1,c11=getchar();
	while(isdigit(c11))x=x*10+c11-'0',c11=getchar();if(ob)x=-x;
}

const int N = 101000 ,p = 1e9+7;
char s[N];int n;
int t[200];

int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;++i) ++t[s[i]-'a'];
	int res = 1;
	for(int i=0;i<26;++i) res = (ll)res * (t[i]+1)%p;
	printf("%d\n",(res-1+p)%p);
	return 0;
}
