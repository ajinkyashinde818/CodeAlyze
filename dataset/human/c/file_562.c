#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main(){

long long int n, a[200010]={}, x, min=9223372036854775807;
long long int i, j;

scanf("%lld", &n);
for(i=1;i<=n;i++){
  scanf("%lld", &a[i]);
  a[i]+=a[i-1];
}

x=a[n];

for(i=1;i<n;i++){
  if(min>llabs(a[i]-(x-a[i]))) min=llabs(a[i]-(x-a[i]));
}


printf("%lld\n", min);
  return 0;
}
