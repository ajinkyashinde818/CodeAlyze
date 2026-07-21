#include<bits/stdc++.h>
using namespace std;

int ap[30];

int main() {
	int n;char c;
  	long long ans = 1, mod = 1000000007;
  	scanf("%d\n",&n);
  	while(n--) {
    	c = getchar();
      	ap[c-'a']++;
    }
  	for(int i='a';i<='z';i++) {
    	ans = (ans * (ap[i-'a']+1)) % mod;
    }
  	printf("%lld\n",ans-1);
}
