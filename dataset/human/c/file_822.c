#include<stdio.h>
#include<math.h>

int main()
{
  int d,g;
  int p[11],c[11];
  int i,j;
  int a,b,e;
  int ans=10000;
  scanf("%d%d",&d,&g);
  for(i=0;i<d;i++){
    scanf("%d%d",&p[i],&c[i]);
  }
  for(i=0;i<(1<<d);++i){
    a=0;
    b=0;
    e=0;
    for(j=0;j<d;j++){
      if(i&(1<<j)){
        a+=100*(j+1)*p[j]+c[j];
        b+=p[j];
      }
      else{
        e=j;
      }
    }
    for(j=0;j<p[e];j++){
      if(a>=g){
        if(ans>b) ans=b;
        break;
      }
      a+=100*(e+1);
      b++;
    }
  }
  printf("%d",ans);
  return 0;
}
