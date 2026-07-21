#include <stdio.h>


int main(int argc, char const *argv[]) {

  int n;
  scanf("%d", &n);

  int a[n];
  int b[n];
  int c[n-1];
  for(int i=0; i < n; i++){
      scanf("%d", &a[i]);
  }
  for(int i=0; i < n; i++){
      scanf("%d", &b[i]);
  }
  for(int i=0; i < n-1; i++){
      scanf("%d", &c[i]);
  }

  int sat = 0;
  for (int i=0; i < n; i++){
      sat += b[i];
  }
  for (int i=0; i < n-1; i++){
      if (a[i] +1 == a[i+1]){
          sat += c[ a[i] - 1 ];
      }
  }

  printf("%d\n", sat);

  return 0;
}
