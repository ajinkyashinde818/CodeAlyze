#include <stdio.h>

int main(void)
{
  long max, first, tmp, num, i;

  scanf("%ld", &num);
  scanf("%ld", &first);
  scanf("%ld", &tmp);
  max = tmp - first;
  if(tmp < first){
    first = tmp;
  }

  for(i = 2; i < num; i++){
    scanf("%ld", &tmp);
    if(max < tmp - first){
      max = tmp - first;
    }
    if(tmp < first){
      first = tmp;
    }
  }

  printf("%ld\n", max);

  return 0;
}
