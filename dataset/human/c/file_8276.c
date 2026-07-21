#include<stdio.h>

int main()
{
  int n,k;
  char s[10];
  scanf("%d",&n);
  (void)getchar();
  scanf("%s",s);
  (void)getchar();
  scanf("%d",&k);

  for ( int i = 0; i < n; i++ ) {
    if ( s[i] != s[k-1] ) {
      printf("*");
    } else {
      printf("%c",s[i]);
    }
  }
  printf("\n");
  return 0;
}
