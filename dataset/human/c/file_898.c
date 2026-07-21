#include <stdio.h>
#include <math.h>

int main(){
  long n;  scanf("%ld", &n);

  int table[300][2] = {0}, len = 0;
  long ncopy = n;
  long sqrtn = sqrt(n);
  long sqrtnc = sqrt(ncopy);
  //    for(long i = 2; i<=sqrt(n); i++){
  for(long i=2; ncopy!=1; i++){
    if(len == 0  &&  i > sqrtn)  break;
    if(i > sqrtnc){
      table[len][0] = ncopy;
      table[len][1]++;
      len++;
      break;
    }
    if(ncopy % i == 0){
      table[len][0] = i;
      while(ncopy % i == 0){
	ncopy /= i;
	table[len][1]++;
      }
      len++;
      sqrtnc = sqrt(ncopy);
    }
  }

  long ans = 0;

  for(int i=0; i<len; i++){
    //    printf("table[%d] %d\n", table[i][0], table[i][1]);
    long count, j;
    for(j=1; ; j++){
      if(j*(j+1)/2 > table[i][1]){
	break;
      }
    }
    ans = ans + (j-1);
  }
      
  if(len == 0)  ans = 1;
  if(n == 1)  ans = 0;

  printf("%ld\n", ans);
  return 0;
}
