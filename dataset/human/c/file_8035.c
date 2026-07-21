#include <ctype.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <signal.h>
#include <stdarg.h>
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
//#pragma GCC optimize("unroll-loops")

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

char m[1000][1001];
int d[1000][1000];
int s[1000000][2];
int main(void){
	int h=nextint();
	int w=nextint();
	int ch=nextint()-1;
	int cw=nextint()-1;
	int dh=nextint()-1;
	int dw=nextint()-1;
	for(int i=0; i<h; i++){
		nextstr(m[i]);
	}
	int k=0;
	int sl=0, sr=0;
	d[ch][cw]=1;
	s[sl][0]=ch, s[sl][1]=cw, sr++;
	while(1){
		k++;
		if(sl==sr) break;
		int tl=sl;
		while(sl<sr){
			int x=s[sl][0], y=s[sl][1]; sl++;
			{int i=x-1, j=y; if(0<=i&&i<h&&0<=j&&j<w && m[i][j]=='.' && d[i][j]==0){ d[i][j]=k; s[sr][0]=i, s[sr][1]=j, sr++;}}
			{int i=x+1, j=y; if(0<=i&&i<h&&0<=j&&j<w && m[i][j]=='.' && d[i][j]==0){ d[i][j]=k; s[sr][0]=i, s[sr][1]=j, sr++;}}
			{int i=x, j=y-1; if(0<=i&&i<h&&0<=j&&j<w && m[i][j]=='.' && d[i][j]==0){ d[i][j]=k; s[sr][0]=i, s[sr][1]=j, sr++;}}
			{int i=x, j=y+1; if(0<=i&&i<h&&0<=j&&j<w && m[i][j]=='.' && d[i][j]==0){ d[i][j]=k; s[sr][0]=i, s[sr][1]=j, sr++;}}
		}
		if(d[dh][dw]!=0){
			printf("%d\n", k-1);
			return 0;
		}
		int tr=sr;
		while(tl<tr){
			int x=s[tl][0], y=s[tl][1]; tl++;
			if(d[x][y]==k){
				for(int i=x-2; i<=x+2; i++){
					for(int j=y-2; j<=y+2; j++){
						if(0<=i&&i<h&&0<=j&&j<w && m[i][j]=='.' && d[i][j]==0){
							d[i][j]=k+1;
							s[sr][0]=i, s[sr][1]=j, sr++;
						}
					}
				}
			}
		}
	}
	printf("%d\n", -1);
}
