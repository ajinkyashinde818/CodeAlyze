#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
//    return *(long long*)a - *(long long*)b;
}
//  qsort(A, b, sizeof(int), compare_int);

int main()
{
 
//  int a, b, c, d, e, X, Y;
  int a, b, c,  d, e,f,n;
  //  double  c;
//  long long  A[1000001]={};
  int  A[2001][1001]={};
  int  B[2000001]={};
  int  ans[100003]={};
  int  sum[100003]={};
  int  cnt_flag[100003]={};

  int  L[1003]={};


//  long long  a, b, c, d, X, Y;
//  long long   d, X, Y;
  long long JPY;
  double BTC;
  char s[200001][1001]={};
  char t[200001][1001]={};
  char u[200001]={};
//  int N, M;
//  int A[1000000001]={};
//  long long  C[101]={};
  int i,j,k,point;
  int point_A=0, point_B=0;
  int flag=0;
//  int flag[10000003]={};
  int tmp=0;
//  int min=1000000;
  int min=10;
  int len=0;
  int cnt=0;
  int cnt0=0;
  int cnt1=0;
  int num=0;
//  double ans=0.0;
//  long long ans=0;
  int max=0;
//  int sum=0;
//  char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  //  a=0;
//  scanf("%lld %lld", &a, &b);
 
  scanf("%d%d%d%d", &a, &b, &c, &n);
  for(i=0;(i*a)<n+1;i++){
    if((i*a)==n){
      cnt++;
      break;
    }
    for(j=0;(i*a)+(j*b)<n+1;j++){
      if((i*a)+(j*b)==n){
        cnt++;
        break;
      }
      else  if((n-((i*a)+(j*b)))%c==0){
          cnt++;
      }//      k=0;
//      if((i*a)+(j*b)+(k*c)>n) break; 
//          printf("i=%d j=%d k=%d n=%d cnt=%d\n",i,j,k,(i*a)+(j*b)+(k*c), cnt);
    }
//  j=0;
//  if((i*a)+(j*b)+(k*c)>n) break;     
//          printf("i=%d j=%d k=%d n=%d cnt=%d\n",i,j,k,(i*a)+(j*b)+(k*c), cnt);
  }
  
  printf("%d\n",cnt);
//    else  
  
return 0;
}
