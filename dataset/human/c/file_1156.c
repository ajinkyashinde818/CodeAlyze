#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_s(const void * left, const void * right)
{
	char *left_char = (char *)left;
  char *right_char = (char *)right;
  return strcmp(left_char, right_char);
}
int cmp_s2(const void * left, const void * right)
{
	char *left_char = (char *)left;
  char *right_char = (char *)right;
  return -strcmp(left_char, right_char);
}

int main(void){

  char s[101], t[101];
  scanf("%s %s", s, t);
	int s_length = strlen(s);
	int t_length = strlen(t);
	qsort(s, s_length, sizeof(char), cmp_s);
	qsort(t, t_length, sizeof(char), cmp_s2);
	if (strcmp(s,t) < 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

  return 0;
}
