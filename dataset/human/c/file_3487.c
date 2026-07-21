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

uint32_t nextpint(void){ char c=getchar_unlocked(); while(c<'0'||'9'<c) c=getchar_unlocked(); uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } return x; }
uint64_t nextplong(void){ char c=getchar_unlocked(); while(c<'0'||'9'<c) c=getchar_unlocked(); uint64_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar_unlocked(); } return x; }

uint32_t a[200001];
uint32_t s[200001];
int main(void){
	uint32_t n=nextpint();
	uint64_t k=nextplong();
	for(uint32_t i=1; i<=n; i++){
		a[i]=nextpint();
	}
	uint32_t now=1;
	for(; k>0; k--){
		now = a[now];
		if(s[now]==0){
			s[now]=k;
		}else{
			uint32_t m=s[now]-k;
			k=(k-1)%m;
			break;
		}
	}
	for(; k>0; k--){
		now = a[now];
	}
	printf("%"PRIu32"\n", now);
}
