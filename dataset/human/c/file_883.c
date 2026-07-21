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

int a[40]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8};
int main(void){
	long n=nextlong();
	int ans=0;
	{int i=2; int b=0; while(n%i==0){ n/=i; b++; } ans+=a[b];}
	{int i=3; int b=0; while(n%i==0){ n/=i; b++; } ans+=a[b];}
	{int i=5; int b=0; while(n%i==0){ n/=i; b++; } ans+=a[b];}
	int m=sqrt(n);
	for(int i=7; i<m;){
		{int b=0; while(n%i==0){ n/=i; b++; } ans+=a[b];}
		i+=4;
		{int b=0; while(n%i==0){ n/=i; b++; } ans+=a[b];}
		i+=2;
	}
	printf("%d\n", ans+(n>1));
}
