#include <stdio.h>
int main(){
int a,s,d,q;
  scanf("%d %d %d",&a,&s,&d);
 for(q=0;q<s;q++){
  printf("%d ",d);
  }if(d>10){d--;
  for(q=a-s;q>0;q--){
  printf("%d ",d);}
  }
  else{d++;
    for(int q=a-s;q>0;q--){
  printf("%d ",d);}
  }
return 0;
}
