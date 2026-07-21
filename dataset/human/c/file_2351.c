#include <float.h>
#include <inttypes.h>
#include <limits.h>
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

int comp(const void *a, const void *b){return (*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}
int compr(const void *a, const void *b){return (*(int*)a<*(int*)b)-(*(int*)a>*(int*)b);}

uint32_t nextpint(void){ char c=getchar(); while(c<'0'||'9'<c) c=getchar(); uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar(); } return x; }
uint64_t nextplong(void){ char c=getchar(); while(c<'0'||'9'<c) c=getchar(); uint64_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar(); } return x; }
uint32_t nextstr(char *s){ char c=getchar(); while(c==' '||c=='\n') c=getchar(); uint32_t len=0; while(c!=' '&&c!='\n'){ *s++=c; len++; c=getchar(); } *s='\0'; return len; }

inline int max2(const int a, const int b){return a>b?a:b;}
inline int min2(const int a, const int b){return a>b?b:a;}
inline int dif2(const int a, const int b){return a>b?a-b:b-a;}
inline int abs2(const int a){return a>=0?a:-a;}

int main(void){
	int n=nextpint();
	int k=nextpint();
	int s=nextpint();
	if(s==1000000000){
		for(int i=0; i<k; i++){
			printf("%d ", 1000000000);
		}
		for(int i=k; i<n; i++){
			printf("%d ", 1);
		}
		putchar(10);
	}else{
		for(int i=0; i<k; i++){
			printf("%d ", s);
		}
		for(int i=k; i<n; i++){
			printf("%d ", 1000000000);
		}
		putchar(10);
	}
}
