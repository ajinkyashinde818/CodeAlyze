//Date:06-01-17
 
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<float.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#define ll long long
#define For(i,n)	for(i=0;i<n;i++)
#define rep(i ,a ,b)	for(i=(a);i<=(b);i++)
#define mset(a ,value)	memset(a ,value ,sizeof(a))
#define s(a)	scanf("%d" ,&a);
#define ls(a)	scanf("%ld" ,&a)
#define reg(i)	register int i
#define infinite INT_MAX
#define MAX 100005
#define NIL -1
int min(int a,int b){	return (a<b?a:b);	}
int max(int a,int b){	return (a>b?a:b);	}
/*main(){
	int sx ,sy ,tx ,ty;
	scanf("%d%d%d%d" ,&sx ,&sy ,&tx ,&ty);
	int x=sx ,y = sy;
	while(y!=ty){	printf("U");	y++;	}
	while(x!=tx){	printf("R");	x++;	}
	while(y!=sy){	printf("D");	y--;	}
	while(x!=sx){	printf("L");	x--;	}
	printf("L");	x--;
	while(y!=(ty+1)){	printf("U");	y++;	}
	while(x!=tx){	printf("R");	x++;	}
	printf("D");	y--;
	printf("R");	x++;
	while(y!=(sy-1)){	printf("D");	y--;}
	while(x!=sx){	printf("L");	x--;	}
	printf("U");	y++;
	assert((x==sx)&&(y==sy));
	return 0;
}*/
main(){
	int k ,s ,x ,y ,z ,c=0;
	scanf("%d %d" ,&k ,&s);
	rep(x ,0 ,k)
		rep(y ,0 ,k){
				z = s-(x+y);
				if(z>=0&&z<=k)	c++;
	}
	printf("%d" ,c);
	return 0;
}
