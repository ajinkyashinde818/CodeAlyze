#include<stdio.h>
#include<stdlib.h>

int main(){
  long n;
  scanf("%ld", &n);
  long a[n];
  for(int i = 0; i < n; i++)
  scanf("%ld", &a[i]);
  
  int zerocount = 0;
  int minuscount = 0;
  
  for(int i = 0; i < n; i++){
    if(a[i] == 0)
      zerocount++;
    else if(a[i] < 0)
      minuscount++;
  }
  
  long ans = 0;
  
  if(zerocount > 0 || minuscount % 2 == 0){
    long b[n];
    for(int i = 0; i < n; i++){
      if(a[i] < 0)
        b[i] = -a[i];
      else
        b[i] = a[i];
    }
    
    for(int i = 0; i < n; i++)
      ans += b[i];
  }
  else{
    long min = 10000000000;
    for(int i = 0; i < n; i++){
      if(abs(a[i]) < min)
        min = abs(a[i]);
    }
    
    long b[n];
    for(int i = 0; i < n; i++){
      if(a[i] < 0)
        b[i] = -a[i];
      else
        b[i] = a[i];
    }
    
    for(int i = 0; i < n; i++)
      ans += b[i];
    ans -= min*2;
  }
  
  printf("%ld", ans);
  return 0;
}
