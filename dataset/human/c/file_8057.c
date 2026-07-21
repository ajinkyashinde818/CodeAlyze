#include <stdio.h>
long long int gcd(long long int a, long long int b)
{
    long long int c;
    if (a < b) {
        a+=b; b=a-b; a-=b;
    }
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main(){
  int t = 0;
  scanf("%d\n",&t);
  long long int a[t],b[t],c[t],d[t];
  int i = 0;
  for(i=0;i<t;i++){
    scanf("%lld %lld %lld %lld",&a[i],&b[i],&c[i],&d[i]);
  }
  long long int tmp=0;
  for(i=0;i<t;i++){
    if(a[i] < b[i] || d[i] < b[i]){
      printf("No\n");
      continue;
    }
    if(b[i]-1<=c[i]){
      printf("Yes\n");
      continue;
    }
    tmp = gcd(d[i],b[i]);
    if(c[i]<b[i]-tmp+(a[i]%tmp)){
      printf("No\n");
    }else{
      printf("Yes\n");
    }
  }
  return 0;
}
