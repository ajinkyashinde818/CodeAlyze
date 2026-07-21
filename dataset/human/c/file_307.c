#include<stdio.h>
#include<string.h>
int zet(long long int a){
  if(a > 0)return a;
  return -a;
}
int main(void){
  int n;
  scanf("%d",&n);
  long long int a,ans = 0,cnt = 0,min = 10000000000;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a);
    if(a < 0){
      cnt++;
    }
    a = zet(a);
    if(min > a)min = a;
    ans += a;
  }
  if(cnt % 2 > 0)ans -= 2 * min;
  printf("%lld\n",ans);
  return 0;
}
