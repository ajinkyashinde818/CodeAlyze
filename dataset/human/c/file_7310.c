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

#define getchar getchar_unlocked
#define putchar putchar_unlocked
int32_t nextint(void){ char c=getchar_unlocked(); while(c!='-'&&(c<'0'||'9'<c)) c=getchar_unlocked(); bool s=false; if(c=='-'){s=true;c=getchar_unlocked();} uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } return s?-x:x; }
int64_t nextlong(void){ char c=getchar_unlocked(); while(c!='-'&&(c<'0'||'9'<c)) c=getchar_unlocked(); int s=0; if(c=='-'){s=1;c=getchar_unlocked();} uint64_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } return s?-x:x; }
uint32_t nextstr(char *s){ char c=getchar_unlocked(); while(c==' '||c=='\n') c=getchar_unlocked(); uint32_t len=0; while(c!=' '&&c!='\n'){ *s++=c; len++; c=getchar_unlocked(); } *s='\0'; return len; }

char s[300][301];
int t[300][300];
int m=1;

void f(int a, int b, int c, int d, int k){
	if(k==1){
		for(int i=a; i<=b; i++){
			for(int j=c; j<=d; j++){
				t[i][j]=m;
			}
		}
		m++;
	}else{
		int x, y;
		for(int i=a; i<=b; i++){
			bool f=false;
			for(int j=c; j<=d; j++){
				if(s[i][j]=='#'){
					x=i; y=j; f=true;
					break;
				}
			}
			if(f) break;
		}
		int i=1;
		for(int j=y+1; j<=d; j++){
			if(s[x][j]=='#') i++;
		}
		if(i==k){
			f(a, b, c, y, 1);
			f(a, b, y+1, d, k-1);
		}else{
			f(a, x, c, d, i);
			f(x+1, b, c, d, k-i);
		}
	}
}

int main(void){
	int h=nextint();
	int w=nextint();
	int k=nextint();
	for(int i=0; i<h; i++){
		nextstr(s[i]);
	}
	f(0, h-1, 0, w-1, k);
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			printf("%d ", t[i][j]);
		}
		putchar(10);
	}
}
