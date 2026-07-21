#include <stdio.h>
int main(int argc, char const *argv[]) {
 int i, j, box[10000];
 i = 0;
 while (i < 10000) {
  scanf("%d", &box[i]);
  if (box[i] == 0) {
   break;
  } /*else{
   printf("case %d: %d\n", i + 1, box[i]);
   i += 1;
  }*/
 i += 1;
 }
 for (j = 0; j < i; j++) {
  printf("Case %d: %d\n", j + 1, box[j]);
 }
 return 0;
}
