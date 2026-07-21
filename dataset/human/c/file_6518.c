#include <stdio.h>
#include <limits.h>

int main(){
  int n, i, list[200000], max = INT_MIN, min;

  scanf("%d", &n);

  for(i=0; i<n; i++) scanf("%d", &list[i]);

  min = list[0];

  for(i = 1; i < n; i++){
    max = max>(list[i]-min)?max:(list[i]-min);
    min = min<list[i]?min:list[i];
  }

  printf("%d\n", max);
  
  return 0;
}
