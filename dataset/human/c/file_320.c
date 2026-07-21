#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define P 1000000007

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}
int compw(const void *a, const void *b){return (*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}
int compr(const void *a, const void *b){return *(int*)b-*(int*)a;}

uint32_t nextpint(void){ char c=getchar(); while(c<'0'||'9'<c) c=getchar(); uint32_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar(); } return x; }
uint64_t nextplong(void){ char c=getchar(); while(c<'0'||'9'<c) c=getchar(); uint64_t x=0; while('0'<=c && c<='9'){ x=x*10+c-'0'; c=getchar(); } return x; }
uint32_t nextstr(char *s){ char c=getchar(); while(c==' '||c=='\n') c=getchar(); uint32_t len=0; while(c!=' '&&c!='\n'){ *s++=c; len++; c=getchar(); } *s='\0'; return len; }

inline int max2(const int a, const int b){return a>b?a:b;}
inline int min2(const int a, const int b){return a>b?b:a;}
inline int dif2(const int a, const int b){return a>b?a-b:b-a;}

int pnt[1002][3];
double dist(const int i, const int j){
	double l=hypot(pnt[i][0]-pnt[j][0], pnt[i][1]-pnt[j][1])-(pnt[i][2]+pnt[j][2]);
	return l>0?l:0;
}
double d[1002];
int q[1002], Q;
int main(void){
	int n;
	scanf("%d%d", &pnt[0][0], &pnt[0][1]);
	scanf("%d%d", &pnt[1][0], &pnt[1][1]);
	d[1]=DBL_MAX;
	q[0]=0;
	q[1]=1;
	scanf("%d", &n);
	for(int i=2; i<n+2; i++){
		scanf("%d%d%d", &pnt[i][0], &pnt[i][1], &pnt[i][2]);
		d[i]=DBL_MAX;
		q[i]=i;
	}
	Q=n+2;
	while(Q>0){
		double min=d[q[0]]; int mini=0;
		for(int i=1; i<Q; i++){
			if(d[q[i]]<min){mini=i; min=d[q[i]];}
		}
		int k=q[mini]; q[mini]=q[Q-1]; Q--;
		for(int i=0; i<Q; i++){
			double D=d[k]+dist(k, q[i]);
			if(D<d[q[i]]) d[q[i]]=D;
		}
	}
	printf("%.10lf\n", d[1]);
}
