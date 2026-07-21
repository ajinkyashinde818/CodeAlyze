#include <stdio.h>
#include <stdlib.h>

int main(void) {
 
  int n,rslt;
  scanf("%d",&n);
  int listA[n+1],listB[n+1],listC[n];
  for(int i=1;i<=n;i++)scanf("%d",&listA[i]);
  for(int i=1;i<=n;i++)scanf("%d",&listB[i]);
  for(int i=1;i< n;i++)scanf("%d",&listC[i]);
  
  rslt = listB[listA[1]];
  for(int i=2;i<=n;i++){
    rslt += listB[listA[i]];
    if(listA[i-1]+1 == listA[i]){
      rslt += listC[listA[i-1]];
    }
  }
  printf("%d\n",rslt);

  return 0;
}
