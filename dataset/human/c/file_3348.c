#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
  char arr[110000];
  char divide[4][10] = {"dream", "dreamer", "erase", "eraser"};

  fgets(arr, sizeof(arr), stdin);
  arr[strlen(arr) - 1] = '\0';  //改行の場所にナル文字

  //文字列を反転させる
  for (int i = 0; i < 4; i++) {
    char t[10];
    size_t siz_s = strlen(divide[i]) - 1;
    int r = 0;
    for (int j = siz_s; j >= 0; j--) {
      t[r] = divide[i][j];
      r++;
    }
      t[r] = '\0';

    for (int j = 0; j <= siz_s; j++) {
      divide[i][j] = t[j];
    }

  }

  size_t siz_arr = strlen(arr);
  char arr_ex[110000];
  int r = 0;

  for (int i = siz_arr-1; i >= 0; i--) {
    arr_ex[r] = arr[i];
    r++;
  }
   arr_ex[r] = '\0';


  bool flag = true;
  int count = 0;

  for (; arr_ex[count] != '\0'; ) {
    int i,j;
    char t[10];
  for (i = count,j=0; i < count + 5; i++,j++) {
    t[j] = arr_ex[i];
  }
    t[j] = '\0';
    if ( strcmp(divide[0], t) == 0) {
      count += 5;
      continue;
    }
    if ( strcmp(divide[2], t) == 0) {
      count += 5;
      continue;
    }
  for (i = count,j=0; i < count + 6; i++,j++) {
    t[j] = arr_ex[i];
  }
    t[j] = '\0';
    if ( strcmp(divide[3], t) == 0) {
      count += 6;
      continue;
    }
  for (i = count,j=0; i < count + 7; i++,j++) {
    t[j] = arr_ex[i];
  }
    t[j] = '\0';
    if ( strcmp(divide[1], t) == 0) {
      count += 7;
      continue;
    }
    
    flag = false;
    break;
  }

  if (flag == false) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }


  return 0;
}
