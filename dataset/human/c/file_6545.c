#include <stdio.h>

int main(){

int r[1000000],i,t,n,j;

  scanf("%d\n",&n);

  for(i=0;i<n;i++){
     scanf("%d\n",&r[i]);
   }
int max,min;
 max = -10000000000;
 min = r[0];

for(j=1;j<n;j++){
if(max<r[j]-min){
 max = r[j]-min;
}
else;

if(min>r[j]){
min = r[j];
}
else;

}


printf("%d\n",max);

return 0;
}
