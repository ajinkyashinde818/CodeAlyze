#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define MOD 1000000007
#define SIZE 100005
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
char str[100001];
int main(void)
{
	int l,r,res=0,i;
	scanf("%s",str);
	l=0; r=strlen(str)-1;
	while(l<r){
		if(str[l]==str[r]) l++,r--;
		else if(str[l]=='x') res++,l++;
		else if(str[r]=='x') res++,r--;
		else{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",res);
	return 0;
}
