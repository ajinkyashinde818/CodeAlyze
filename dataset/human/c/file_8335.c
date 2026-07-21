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


int main(){
  char buf[1024];
  char S[12];
  int N;
  int K;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  fgets(S,sizeof(S),stdin);

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &K);

  rep(i,N){
    if(S[i]!=S[K-1]){
      S[i]='*';
    }
  }

  printf("%s\n",S);

  return 0;


}
