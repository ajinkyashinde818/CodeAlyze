#include <stdio.h>

int main (void){
  int d,i,s;
  int saidai,hikaku,saisyou;
  int a[200000];
  i=0;
  saidai=-10000000000;
  saisyou=6000000;
 scanf("%d",&d);
  while(d>i){
    scanf("%d",&a[i]);
    i++;
  }
  saisyou=a[0];
  for(i=0;i<d;i++){
    while(a[i]>saisyou){
      i++;
    }
saisyou=a[i];
    for( s=d-1;s>i;s--){
      hikaku=a[s]-a[i];
      if(hikaku>saidai){
	saidai=hikaku;
     }
    }
  }
 printf("%d\n",saidai);
  return 0;
}
