#include <stdio.h>

int comp(char *str, char *S, int n, int j){
  char str0[10];

  if((j-n+1)<0) return 0;
  strncpy(str0, &S[j - n + 1], n);
  str0[n] = '\0';
  //printf("%d:%s\n", n,str0);
  if (strncmp(str0, str, n) == 0) {
    //printf("%s\n", str0);
    return 0;
  } else {
    return 1;
  }
}

int main() {
  char S[100010];
  int i, j, N, n;
  char str0[10];
  char str1[] = "dream";
  char str2[] = "dreamer";
  char str3[] = "erase";
  char str4[] = "eraser";
  int err = 0;

  scanf("%s", S);

  for (i = 0; i <= 100000; i++) {
    if (S[i] == '\0') {
      N = i - 1;
      break;
    }
  }

  n = 0;
  for (j = N; j >= 0; j = j - n) {
    //printf("j:%d\n", j);
    switch (S[j]) {
      case 'm':
        n = 5;
        err = comp(str1, S, n, j);
        break;
      case 'r':
        switch (S[j - 2]) {
          case 'm':
            n = 7;
            err = comp(str2, S, n, j);
            break;
          case 's':
            n = 6;
            err = comp(str4, S, n, j);
            break;
          default:
            err = 1;
            break;
        }
        break;
      case 'e':
        n = 5;
        err = comp(str3, S, n, j);
        break;
      default:
        err = 1;
        break;
    }
    //if(j-n < 0) err = 1;
    //printf("n:%d\n", n);
    if(err != 0){
      printf("NO");
      return 0;
    }
  }

  printf("YES");
  return 0;
}
