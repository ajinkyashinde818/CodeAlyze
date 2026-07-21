#include <stdio.h>
int main (){
  int i,n,k[100],p[100];
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d %d",&k[i],&p[i]);
    if (k[i]%p[i]==0){
      printf("%d\n",p[i]);
    }
    else {
       printf("%d\n",k[i]%p[i]);
    }
  }
  return 0;
}
