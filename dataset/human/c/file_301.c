#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000

int min(int a, int b){
  if(a>=b){
    return b;
  }
  else{
    return a;
  }
}

int main(){
  char buf[1024];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  int *A=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    scanf("%d",&A[i]);
  }

  int count=0;
  int min_a=abs(A[0]);
  long sum=0;
  rep(i,N){
    if(A[i]<0){
      count++;
      A[i]=A[i]*(-1);
    }
    min_a=min(min_a, A[i]);
    sum+=A[i];
  }

  long ans;
  if(count%2==0){
    ans=sum;
  }
  else{
    ans=sum-2*min_a;
  }

  printf("%ld\n", ans);

  return 0;

}
