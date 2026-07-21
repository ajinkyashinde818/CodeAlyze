#include<stdio.h>
#include<string.h>
int main()
{
  char s[100001], t1[]={"dream"}, t2[]={"dreamer"}, t3[]="erase", t4[]="eraser";
  int i, j, f=0;

  scanf("%s", s);
  
  i = strlen(s);
  while( i > 0  ){
    if( i >=5 && strncmp( &s[i-5], t1, strlen(t1)) == 0) {
       i -= strlen(t1);
    } else  if( i >=7 && strncmp( &s[i-7], t2, strlen(t2)) == 0) {
       i -= strlen(t2);
    } else  if( i >=5 && strncmp( &s[i-5], t3, strlen(t3)) == 0) {
       i -= strlen(t3);
    } else  if( i >=6 && strncmp( &s[i-6], t4, strlen(t4)) == 0) {
       i -= strlen(t4);
    } else {
       f = 1;
       break;
    }
  }

  if( f ) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }

  return 0;
}
