#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <signal.h>
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
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define getchar getchar_unlocked
#define putchar putchar_unlocked
int32_t nextint(void){ char c=getchar(); while(c!='-'&&(c<'0'||'9'<c)) c=getchar(); bool s=false; if(c=='-'){s=true;c=getchar();} uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar(); } return s?-x:x; }
int64_t nextlong(void){ char c=getchar(); while(c!='-'&&(c<'0'||'9'<c)) c=getchar(); int s=0; if(c=='-'){s=1;c=getchar();} uint64_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar(); } return s?-x:x; }
uint32_t nextstr(char *s){ char c=getchar(); while(c==' '||c=='\n') c=getchar(); uint32_t len=0; while(c!=' '&&c!='\n'){ *s++=c; len++; c=getchar(); } *s='\0'; return len; }

void rsorta_d32(void *base, const int count, const int size, const int index){
	typedef int32_t rsort_t;
	rsort_t (*a)[size] = (rsort_t(*)[size])base;
	rsort_t (*b)[size] = (rsort_t(*)[size])malloc(count*size*sizeof(rsort_t));
	int c[0x100];
	for(int k=0; k<4; k++){
		memset(c, 0, sizeof(c)); for(int i=0; i<count; i++){ c[(a[i][index]>>(k<<3))&0xFF]++; } for(int i=1; i<0x100; i++) c[i]+=c[i-1]; for(int i=count-1; i>=0; i--){ int to=--c[(a[i][index]>>(k<<3))&0xFF]; for(int j=0; j<size; j++){ b[to][j]=a[i][j]; } }{rsort_t(*t)[size]=a; a=b; b=t;}
	}
	free(b);
}
#define P 1000000007
int a[200000];
int b[200000];
int al, bl;
int main(void){
	int n=nextint();
	int k=nextint();
	for(int i=0; i<n; i++){
		int s=nextint();
		if(s>=0){
			a[al++]=s;
		}else{
			b[bl++]=-s;
		}
	}
	rsorta_d32(a, al, 1, 0);
	rsorta_d32(b, bl, 1, 0);
	long ans=1;
	if(n==k){
		for(int i=0; i<al; i++){
			ans=ans*a[i]%P;
		}
		for(int i=0; i<bl; i++){
			ans=ans*b[i]%P;
		}
		if(bl%2==1) ans=-ans;
	}else if(k%2==1 && al==0){
		for(int i=0; i<k; i++){
			ans=ans*b[i]%P;
		}
		ans=-ans;
	}else{
		while(k>1){
			if(al<2){
				ans=ans*b[--bl]%P;
				ans=ans*b[--bl]%P;
				k-=2;
			}else if(bl<2){
				ans=ans*a[--al]%P;
				k--;
			}else if((long)a[al-1]*a[al-2]<(long)b[bl-1]*b[bl-2]){
				ans=ans*b[--bl]%P;
				ans=ans*b[--bl]%P;
				k-=2;
			}else{
				ans=ans*a[--al]%P;
				k--;
			}
		}
		if(k==1){
			ans=ans*a[--al]%P;
		}
	}
	ans=(ans+P)%P;
	printf("%ld\n", ans);
}
