#include <stdio.h>
#define M 1000000007

int
main(int argc, char *argv[])
{
  char s[1000001] = {}; int n;
  scanf("%d", &n);
  scanf("%s", s);

  int d[100] = {};
  int i = 0; int cnt = 0;
  while(s[i] != 0){
    if(d[s[i] - 'a'] == 0) cnt++;
    d[s[i] - 'a']++;
    i++;
  }

  unsigned long long ans = (1 << cnt) % M, temp;
  
  for(int j = 0; j < 26; j++){
    if(d[j] != 0){
      temp = (ans * ((M + 1)/2)) % M;
      ans = ((1 + d[j]) * temp) % M;
    }
  }

  printf("%llu\n", ans - 1);
  

  return 0;
}
