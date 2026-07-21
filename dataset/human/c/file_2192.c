#include <stdio.h>
#include <string.h>
#define MAX 200005

void putsinv(char s[], int n)
{
  while (n--) putchar(s[n]);
}

int main(void)
{
  char s[MAX];
  char u[MAX];
  char v[MAX];
  int q, d = 0, i, id = 0, idx = 0;
  
  scanf("%s%d", s, &q);
  
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1)
      d++;
    else {
      int f;
      char c, ch;
      scanf("%d%c%c", &f, &c, &ch);
      if ((d + f) % 2)
        u[id++] = ch;
      else
        v[idx++] = ch;
    }
  }
  
  u[id] = '\0';
  v[idx] = '\0';
  
  if (d % 2 == 0) {
    putsinv(u, id);
    printf("%s%s", s, v);
  } else {
    putsinv(v, idx);
    putsinv(s, strlen(s));
    printf("%s", u);
  }
  
  putchar('\n');
  
  return 0;
}
