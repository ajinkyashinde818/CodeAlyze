#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 100
#define ARRAY_SIZE (STRING_LENGTH + 1)

void solve(char s[ARRAY_SIZE], char t[ARRAY_SIZE]);
int comp(const void *x, const void *y);
int reverse_comp(const void *x, const void *y);


int main()
{
  char s[ARRAY_SIZE], t[ARRAY_SIZE];

  scanf("%s %s", &s, &t);
  solve(s, t);

  return 0;
}

void solve(char s[ARRAY_SIZE], char t[ARRAY_SIZE])
{
  char v[strlen(s) + 1], w[strlen(t) + 1];

  strncpy(v, s, strlen(s));
  v[sizeof(v) - 1] = '\0';
  strncpy(w, t, strlen(t));
  w[sizeof(w) - 1] = '\0';
  qsort(v, sizeof(v)/sizeof(v[0]) - 1, sizeof(v[0]), comp);
  qsort(w, sizeof(w)/sizeof(w[0]) - 1, sizeof(w[0]), reverse_comp);
  
  v[sizeof(v) - 1] = '\0';
  w[sizeof(w) - 1] = '\0';
  
  if (strcmp(v, w) < 0)
    {
      printf("Yes\n");
    }
  else
    {
      printf("No\n");
    }
}
  

int comp(const void *x, const void *y)
{
  return *(char *)x - *(char *)y;
}

int reverse_comp(const void *x, const void *y)
{
  return *(char *)y - *(char *)x;
}
