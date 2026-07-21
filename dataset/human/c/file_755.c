#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  int cnt[26]={0};
  const int mod=1000000007;
  int i;
  for(i=0;i<n;i++) cnt[s[i]-'a']++;
  int ans=1;
  for(i=0;i<26;i++) ans=(int64)ans*(cnt[i]+1)%mod;
  printf("%d\n",(ans+mod-1)%mod);
}

int main(void){
  run();
  return 0;
}
