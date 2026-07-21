#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*

6
10
20
40
41
60
70

two triangles: (10 40 41) and (20 60 70)
but program which see only continuous triplets returns 0
*/

/*
0 < a < b < c < d
to suru

sankakukei ga dekiru zyouken
b+c>d
c+d>b => zimei
d+b>c => zimei
d-c<b => b+c>d
d-b<c => b+c>d
c-b<d => d+b>c => zimei

a+c>d => b+c>d
a+b>d => b+c>d

yotte ookikute renzoku de toreru yatu kara toreba yoi

A X a B C b c A+B>C => X+B>C
A a X B C b c A+B>C => a+B>C a+b>c => X+b>c
A a B X C b c A+B>C => a+X>C a+b>c => B+b>c
A a B C X b c a+b>c => B+b>c A+B>C => a+C X -> a+B>C X+b>c
A a B C b X c A+B>C a+b>c => a+B>C b+X>c

yotte 6 ko renzoku wo mireba yoi
*/

long long read_ll(void) {
	long long ret=0;
	int input;
	while(isspace(input=getchar()));
	ungetc(input,stdin);
	while(isdigit(input=getchar()))ret=ret*10+(input-'0');
	return ret;
}

void print_ll(long long n) {
	char buf[64];
	char *p=buf;
	if(n<0){putchar('-');n=-n;}
	do {
		*(p++)=(char)(n%10+'0');
	} while((n/=10)>0);
	do {
		putchar(*(--p));
	} while(p!=buf);
}

int comp_ll(const void *x,const void *y) {
	long long a=*((long long*)x);
	long long b=*((long long*)y);
	if(a>b)return 1;
	if(a<b)return -1;
	return 0;
}

int main(void) {
	int N;
	static long long a[100000];
	static long long dp[3][100010]; /* [left][pos] */
	long long ret=0;
	int left=2;
	int i;
	if(scanf("%d",&N)!=1)return 1;
	for(i=0;i<N;i++)a[i]=read_ll();
	qsort(a,N,sizeof(a[0]),comp_ll);
	for(i=N-3;i>=0;i--) {
		if(a[i]+a[i+1]>a[i+2]) {
			ret+=a[i]+a[i+1]+a[i+2];
			i-=2;
			left--;
			if(left<=0)break;
		}
	}
	if(left>0)ret=0;
	for(i=N-6;i>=0;i--) {
		static const int ptn[10][6]={
			{0,1,2,3,4,5},
			{0,1,3,2,4,5},
			{0,1,4,2,3,5},
			{0,1,5,2,3,4},
			{0,2,3,1,4,5},
			{0,2,4,1,3,5},
			{0,2,5,1,3,4},
			{0,3,4,1,2,5},
			{0,3,5,1,2,4},
			{0,4,5,1,2,3}
		};
		int j,ok=0;
		for(j=0;j<10;j++) {
			if(a[i+ptn[j][0]]+a[i+ptn[j][1]]>a[i+ptn[j][2]] &&
			a[i+ptn[j][3]]+a[i+ptn[j][4]]>a[i+ptn[j][5]]) {
				ok=1;break;
			}
		}
		if(ok) {
			long long cur=a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5];
			if(cur>ret)ret=cur;
		}
	}
	print_ll(ret);
	putchar('\n');
	return 0;
}
