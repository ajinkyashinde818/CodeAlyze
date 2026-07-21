#include <stdio.h>


int main(){
  int n,i, ans,res,min,tag;
  scanf("%d",&n);
  scanf("%d",&min);
  scanf("%d", &tag);
    ans = tag - min;
    if (tag < min ) { min = tag;}
  for ( i = 0; i < n-2; i++){
    scanf("%d", &tag);
    res = tag - min;
        if (tag < min ) { min = tag;}
    if ( res > ans){ans = res;}
  }
  printf("%d\n",ans );



  return 0;
}
