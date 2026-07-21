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

int gcd(int a, int b){
  if(a<b){
    int temp=a;
    a=b;
    b=temp;
  }
  int temp=a%b;
  while(temp!=0){
    a=b;
    b=temp;
    temp=a%b;
  }
  return b;
}


int main(){
  char buf[1024];
  int A, B, K;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d %d", &A, &B, &K);

  int n=gcd(A,B);

  int count=0;
  int support;
  SREP(i, 1, n){
    if(n%i==0){
      count++;
    }
    if(count==K){
      support=i;
      break;
    }
  }

  int ans=n/support;
  printf("%d\n", ans);

  return 0;
}
