#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int c(const void*a,const void*b){
	if(*(char*)a<*(char*)b)return -1;
	if(*(char*)a>*(char*)b)return 1;
	return 0;
}
int c2(const void*a,const void*b){
	if(*(char*)a<*(char*)b)return 1;
	if(*(char*)a>*(char*)b)return -1;
	return 0;
}

char s[110],t[110];
int main(){
	scanf("%s%s",s,t);
	ll sn=strlen(s);
	ll tn=strlen(t);
	qsort(s,sn,1,c);
	qsort(t,tn,1,c2);
	puts(strcmp(s,t)<0?"Yes":"No");
}
