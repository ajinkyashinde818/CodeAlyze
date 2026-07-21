#include <stdio.h>
int main(){
  int n, k, p,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&k,&p);
    if(k%p!=0){
    printf("%d\n",k%p);
    }else printf("%d\n",p);
  }
  
  return 0;
}
