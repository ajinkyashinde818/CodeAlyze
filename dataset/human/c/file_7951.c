#include <stdio.h>

int main(void){

  int n,k,c;
  scanf("%d %d %d", &n, &k, &c);

	char s[n];
	scanf("%s", s);

  int first[k];
  int last[k];
  int work = 0;
  int day;

  for (day = 0; work < k; day++) {
    if (s[day] == 'o') {
      first[work] = day;
      day += c;
      work++;
    }
  }

  work = 0;
  for (day = n-1; work < k; day--) {
    if (s[day] == 'o') {
      last[work] = day;
      day -= c;
      work++;
    }
  }

  for (int i = 0; i < k; i++) {
    if (first[i] == last[k-i-1]) {
      day = first[i]+1;
      printf("%d\n", day);
    }
  }

  return 0;
}
