#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#ifdef __cplusplus
#include <bits/stdc++.h>
#endif

int32_t nextint(void){ char c=getchar_unlocked(); while(c!='-'&&(c<'0'||'9'<c)) c=getchar_unlocked(); bool s=false; if(c=='-'){s=true;c=getchar_unlocked();} uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } return s?-x:x; }
int64_t nextlong(void){ char c=getchar_unlocked(); while(c!='-'&&(c<'0'||'9'<c)) c=getchar_unlocked(); int s=0; if(c=='-'){s=1;c=getchar_unlocked();} uint64_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } return s?-x:x; }

void rsort(void *base, const int count){
	uint64_t *a=base;
	uint64_t *b=malloc(count*sizeof(uint64_t));
	int c[0x100];
	for(int k=0; k<8; k++){
		memset(c, 0, sizeof(c)); for(int i=0; i<count; i++){ c[(a[i]>>(k<<3))&0xFF]++; } for(int i=1; i<0x100; i++) c[i]+=c[i-1]; for(int i=count-1; i>=0; i--){ b[--c[(a[i]>>(k<<3))&0xFF]]=a[i]; }{void *t=a; a=b; b=t;}
	}
	free(b);
}

int prev1[200001], rank1[200001];
int prev2[200001], rank2[200001];

void init(int n){
	for(int i=1; i<=n; i++){ prev1[i]=i; rank1[i]=1; }
	for(int i=1; i<=n; i++){ prev2[i]=i; rank2[i]=1; }
}
int root1(int x){
	return prev1[x]==x?x:(prev1[x]=root1(prev1[x]));
}
int root2(int x){
	return prev2[x]==x?x:(prev2[x]=root2(prev2[x]));
}
void join1(int x, int y){
	x=root1(x), y=root1(y);
	if(x==y) return;
	if(rank1[x]<rank1[y]){
		prev1[x]=y;
	}else if(rank1[x]>rank1[y]){
		prev1[y]=x;
	}else{
		prev1[x]=y;
		rank1[y]++;
	}
}
void join2(int x, int y){
	x=root2(x), y=root2(y);
	if(x==y) return;
	if(rank2[x]<rank2[y]){
		prev2[x]=y;
	}else if(rank2[x]>rank2[y]){
		prev2[y]=x;
	}else{
		prev2[x]=y;
		rank2[y]++;
	}
}

int n;
long d[200001];
long s[200001];
int bs(long k){
	int l=1, r=n;
	while(l<=r){
		int m=(l+r)/2;
		if(s[m]>=k) r=m-1; else l=m+1;
	}
	return l;
}
int main(void){
	n=nextint();
	int k=nextint();
	int l=nextint();
	init(n);
	for(int i=0; i<k; i++){
		int a=nextint();
		int b=nextint();
		join1(a, b);
	}
	for(int i=0; i<l; i++){
		int a=nextint();
		int b=nextint();
		join2(a, b);
	}
	for(int i=1; i<=n; i++){
		int k1=root1(i);
		int k2=root2(i);
		s[i]=d[i]=(long)k1*n+k2;
	}
	rsort(s+1, n);
	for(int i=1; i<=n; i++){
		int ans=bs(d[i]+1)-bs(d[i]);
		printf("%d ", ans);
	}
	putchar(10);
}
