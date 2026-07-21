#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>	
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define TYPE int
#define MEMSET(a) memset(a,0,sizeof(a))
const int mod=(int)1e09+7;

int in(void){
	int i;scanf("%d",&i);
	return i;
}
long long llin(void){
	long long i;scanf("%lld",&i);
	return i;
}
double din(void){
	double i;scanf("%lf",&i);
	return i;
}
void chin(char s[]){
	scanf("%s",s);
}
void print(int a){
	printf("%d\n",a);
}
void llprint(long long a){
	printf("%lld\n",a);
}
void dprint(double a){
	printf("%.10f\n",a);
}
void print2(int a,int b){
	printf("%d %d\n",a,b);
}
long long max(long long a,long long b){
	return a>b?a:b;
}
long long min(long long a,long long b){
	return a<b?a:b;
}
long long llabs(long long a){
	return a>0?a:-a;
}
double dmax(double a,double b){
	return a>b?a:b;
}
int cmp(const void *a,const void *b){
	return *(TYPE *)a-*(TYPE *)b;
}
int cmp_r(const void *a,const void *b){
	return *(TYPE *)b-*(TYPE *)a;
}
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int c[8][8]={{1,2,1,2,1,4,1,4},{1,2,1,4,1,4,1,2},{1,4,1,2,1,2,1,4},{1,4,1,4,1,2,1,2},
	{2,1,2,1,4,1,4,1},{2,1,4,1,4,1,2,1},{4,1,2,1,2,1,4,1},{4,1,4,1,2,1,2,1}};

int main(void){
	int p[8],i,j,min,now,id;
	while(scanf("%d %d %d %d %d %d %d %d",p,p+1,p+2,p+3,p+4,p+5,p+6,p+7)!=EOF){
		min=inf;
		rep(i,8){
			now=0;
			rep(j,8){
				if(p[j]-c[i][j]>0)
					now+=p[j]-c[i][j];
			}
			if(min>now){
				id=i;
				min=now;
			}
		}
		rep(i,8)
			printf("%d%c",c[id][i],i==7?'\n':' ');
	}
	return 0;
}
