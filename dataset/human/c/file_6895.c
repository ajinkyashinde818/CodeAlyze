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

long long  factorial(long long n) {
    if (n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

int distance(int a, int b) {
  return abs(a-b)*abs(a-b);
}

int ans_gu_choki_per(char te, int c, int d, int e ) {
  if(te = "r") return e;
  else if(te = "s") return c;
  else if(te = "p") return d;
  else return 0;
//  return abs(a-b)*abs(a-b);
}
int ans_gu_choki_per_2(char te, int c, int d, int e ) {
  if(te = "r") return c;
  else if(te = "s") return d;
  else if(te = "p") return e;
  else return 0;
//  return abs(a-b)*abs(a-b);
}

//int ()
/*
int triangle(int a, int b, int c){
  if(a<b+c){
    if(b<c+a){
      if(c<a+b){
        printf("1\n");
        return 1;
      }
    }
  }
  printf("1\n");
  return 0;
}
*/

int main()
{
  int  a ,b, c, d, e, X, Y ,r;
//  long long  a, b, c, d, e, X, Y;
  //  double  c;
//  int  A[200003]={};
  int  A[100003]={};
  int  B[100003]={};
  int  C[100003][100001]={};

  int  flg=0;

//  char s[101][101]={};
  char s[100001]={};
  char t[100001]={};
//  int N, M;
//  int A[1000000001]={};
//  long long  C[101]={};
  int i,j,k;
  long long p,q;
//  int flag=0;
//  int tmp=0;
//  char tmp[101]={};
//  long long min=10000000000;
//  long long min=100000001;
  int len=0;
  int l=0;
//  int r=1000001;
  int cnt=0;
  int num=0;
  int num1=0;
  int num2=0;
  int ans_ac=0;
  int ans_wa=0;
  int max=0;
  int sum=0;
  int addr=0;
  int ptn=0;
  long long  tmp=0;
//  bool on_off[100]={};
  
//  char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  //  a=0;
  scanf("%d%d", &a, &b);
  if(a==b)   printf("Yes\n");
  else    printf("No\n");
  
return 0;
}
