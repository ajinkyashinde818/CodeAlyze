#include <stdio.h>

int main(void)
{
  long long int n,k,length = 0,notloop = 0,now = 1,dupl = -1,l_c = 1;

  scanf("%lld %lld",&n,&k);

  long long int a[n],l[n];
  int c[n];
  
  for(long long int i=0; i<n; i++){
    scanf("%lld",&a[i]);
    c[i] = -1;
  }
  c[0] = 0;
  l[0] = 1;
  
  for(long long int i=0; i<k; i++){
    now = a[now - 1];
    c[now - 1]++;
    l[l_c] = -1;
    if(c[now - 1] == 1){
      dupl = now;
      break;
    }
    else
      l[l_c++] = now;
  }
  if(dupl == -1)
    printf("%lld\n",now);
  else{
    for(long long int i=0; i<n; i++){
      if(l[i] == dupl)
        notloop = i;
      if(l[i] == -1){
        length = i - notloop;
        break;
      }
    }
    if(length == 0)
      length = n - notloop;
    printf("%lld\n",l[(k-notloop)%length+notloop]);
  }
  return 0;
}
