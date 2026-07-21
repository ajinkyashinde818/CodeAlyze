#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int calc(const int bit,int *p,int *c,int g,int d){
  int score=0;
  int res=0;
  int i;
  for(i=0;i<=d;i++){
    if((bit>>i)&0x01){
      score+=p[i]*i*100+c[i];
      res+=p[i];
    }
  }
  i=d;
  while(score<g && i>0){
    if(((bit>>i)&0x01)==0){
      int k=(g-score)/(i*100);
      if(k>p[i]) k=p[i];
      score+=k*i*100;
      res+=k;
    }
    i--;
  }
  return score>=g?res:10*100+1;
}

void run(void){
  int d,g;
  scanf("%d%d",&d,&g);
  int p[11];
  int c[11];
  p[0]=c[0]=0;
  int i;
  for(i=1;i<=d;i++) scanf("%d%d",p+i,c+i);

  int min=100*10+1;
  for(i=0;i<(1<<d);i++){
    int t=calc(i<<1,p,c,g,d);
    if(t<min) min=t;
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
}
