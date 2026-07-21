#include <stdio.h>
#include <string.h>

void selection_s(char a[], int N);
void selection_l(char a[], int N);

int main(void)
{

  char s[105];
  char a[105];

  fgets(s, sizeof(s), stdin);
  fgets(a, sizeof(a), stdin);

  //選択整列法を使用
  //sを小さい順でソート
  selection_s(s, strlen(s)-2);
  selection_l(a, strlen(a)-2);

  int str_siz = strcmp(s, a);

  if (str_siz < 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }


  
  return 0;
}

void selection_s(char a[], int N)
{
  int min;
  char t;

  for (int i = 0; i < N; i++) {

    min = i;

    for (int j = i+1; j <= N; j++) {
      if (a[j] < a[min]) {min = j;}
    }

    t = a[min];
    a[min] = a[i];
    a[i] = t;

  }
}

void selection_l(char a[], int N)
{
  int min;
  char t;

  for (int i = 0; i < N; i++) {

    min = i;

    for (int j = i+1; j <= N; j++) {
      if (a[j] > a[min]) {min = j;}
    }

    t = a[min];
    a[min] = a[i];
    a[i] = t;

  }
}
