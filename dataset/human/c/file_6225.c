#include<stdio.h>

int main(void){
  int rate[200000],n,i,max,min;
  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&rate[i]);
  max=rate[1]-rate[0];
  min=rate[0];
    for(i=1;i<n;i++){
      if(max<rate[i]-min) max=rate[i]-min;
      if(min>rate[i]) min=rate[i];
    }
  printf("%d\n",max);
  return 0;
}
