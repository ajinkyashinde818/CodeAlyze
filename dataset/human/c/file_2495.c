#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[26];
int main(){
	rep(i,0,3){
		char c;
		scanf("%c",&c);
		s[c-'a']++;
	}
	puts(s[0]&&s[1]&&s[2]?"Yes":"No");
}
