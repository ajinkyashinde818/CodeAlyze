#include <stdio.h>

#define n 200000

int main() 
{
 int num, i, minv, maxv, a[n];

 scanf ("%d", &num);
  
  for (i = 0; i < num; i++) {
   scanf ("%d", &a[i]);
}

 maxv = a[1] - a[0];
 minv = a[0];
   
  for (i = 1; i < num; i++) {
    if (maxv <= ( a[i] - minv) ) {
		maxv = a[i] - minv ;
}

    if (minv >= a[i]) {
		minv = a[i];
}
}

 printf("%d\n", maxv);
 return 0;

}
