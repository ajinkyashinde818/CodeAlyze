#include<stdio.h>

int main(){
int j, n, t, R[200000], max, min;
scanf("%d", &n);
for (t=0;t<n;t++){
  scanf("%d", &R[t]);
 }

min=R[0];
max=R[1]-R[0];

for(j=1;j<n;j++){
  if(max < R[j]-min){
    max = R[j] - min;
  }
  else if(max > R[j]-min){
    max = max;
  }
  if(min > R[j]){
    min = R[j];
  }
  else if(min < R[j]){
    min = min;
  }
 }

printf("%d\n", max);

return 0;
}
