#include <stdio.h>

int main(){
  int q,a[2]={499999,500000},t,f,g=0;
  char s[1000000],c[2];
  scanf("%s",&s[a[1]]);
  while(s[a[1]]!=0) a[1]++;
  scanf("%d",&q);
  for(;q>0;q--){
    scanf("%d",&t);
    if(t==1){
      g^=1;
    }else{
      scanf("%d",&f);
      f--;
      f^=g;
      scanf("%s",&c);
      s[a[f]]=c[0];
      a[f]+=(f<<1)-1;
    }
  }
  s[a[1]]=0;
  a[0]++; a[1]--;
  if(g){
    f=(a[0]+a[1]);
    for(q=a[0];q<=f/2;q++){
      t=s[q];
      s[q]=s[f-q];
      s[f-q]=t;
    }
  }
  printf("%s",&s[a[0]]);
  return(0);
}
