#include <stdio.h>
long long absol(long long);
int main(){
  int n;
  long long a[100000],sum=0,par=0,min=1000000001;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    scanf("%lld",&a[i]);
    if (a[i]<0) par++;
    a[i]=absol(a[i]);
    sum+=a[i];
    if (min>a[i]) min=a[i];
  }
  if (par%2) printf("%lld\n",sum-2*min);
  else printf("%lld\n",sum);
  return 0;
}

long long absol(long long x){
  if (x<0) x=-x;
  return x;
}
