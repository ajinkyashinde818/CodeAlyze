#include <stdio.h>
main () {
int i,j,x;
int box[10001];
scanf("%d",&x);
for(i=1;x!=0;i++){
if(x!=0){
  box[i] = x;
  scanf("%d",&x);
}
}
for(j=1;j<i;j++){
  printf("Case %d: %d\n",j,box[j]);
}
return 0;
}
