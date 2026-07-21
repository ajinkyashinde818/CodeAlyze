#include <stdio.h>

long dif(long a,long b){
  if(b-a>0){
    return b-a;
  }else{
    return a-b;
  }
}

long main(){
  long n,sunuke=0,arai=0,sum,ans,i,box;
  long a[200005];
  scanf("%ld",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);  
  }
  for(i=0;i<n-1;i++){
    a[i+1] += a[i];
  }  
  sum = a[n-1];
  for(i=0;i<n-1;i++){
    box = dif(a[i],sum-a[i]);
    if(i==0){
      ans = box;
    }else{
      if(box<ans){
        ans = box;
      }
    }
  }
  printf("%ld",ans);
  return 0;
}
