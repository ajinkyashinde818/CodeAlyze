#include <stdio.h>
#include <math.h>

int main(void) {
  long N,n,Mx,Mn,Mn2;
  scanf("%ld\n",&N);
  scanf("%ld\n",&Mn);
  scanf("%ld\n",&Mx);

  if (Mx>Mn) Mn2=Mn;
  else       Mn2=Mx;
  for(n=2;n<N;n++) {
    long R;
    scanf("%ld\n",&R);

    if(Mx<R) {
      Mx=R;
      if (Mn2<Mn) Mn=Mn2;
    }
    if ((R-Mn2)>(Mx-Mn)) {
      Mx=R;
      Mn=Mn2;
    }
    if (Mn2>R) {
      Mn2=R;
    }
  }
  printf("%ld\n",Mx-Mn);
  return 0;
}
