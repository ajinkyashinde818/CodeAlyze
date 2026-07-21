#include <stdio.h>

int main(void){
  long K, N;
  long x = -1;
  scanf("%ld %ld", &K, &N);
  long i;
  long first, old_, new_;
  scanf("%d", &first);
  old_ = first;
  for(i = 1; i < N; i++){
    scanf("%d", &new_);
    if(x == -1 || x < new_ - old_)x = new_ - old_;
    old_ = new_;
  }
  if(x < K - (new_ - first)) x = K - (new_ - first);
  printf("%d\n", K - x);
  return 0;
}
