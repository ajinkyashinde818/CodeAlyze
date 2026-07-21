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
 
  int a, b, c, d, e, X, Y;
  //  double  c;
  int  A[101]={};
//  int  B[100003]={};
  int  L[1003]={};

  int  flag[103]={};

//  long long  a, b, c, d, X, Y;
char s[101][101]={};
  long long JPY;
  double BTC;
char t[101][101]={};
//  int N, M;
//  int A[1000000001]={};
//  long long  C[101]={};
  int i,j,k;
//  int flag=0;
  double tmp=0;
//  int min=1000000;
  long long min=100000001;
  int len=0;
  int cnt=0;
  int num=0;
//  double ans=0.0;
  int ans=0.0;
  int max=0;
  int sum=0;
//  char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  //  a=0;
//  scanf("%lld %lld", &a, &b);
  scanf("%d%d%d", &a, &b, &c);

  for(i=1;i<101;i++){
//           printf("%d cnt%d\n",i, cnt);
    if((a%i)==0){
      if((b%i)==0){
        A[cnt]=i;
        cnt++;
      }
    }
  }
  printf("%d\n",A[cnt-c]);

  //    if(max < cnt - max)  printf("Yes\n");
//    else  
  
return 0;
}
