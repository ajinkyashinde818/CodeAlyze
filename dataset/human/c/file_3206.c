#include<stdio.h>
#define rep(a,b) for(long int i = a;i <= b;i++)

int main(void){
  //acquisition of data
  long int k,n; scanf("%ld%ld",&k,&n);
  long int a[200010],b[200010]; rep(1,n){scanf("%ld",&a[i]);}

  //b[i]:distance between i and i+1
  rep(1,n){
    if(i != n){b[i] = a[i+1] - a[i];}
    else{b[n] = k - (a[n]-a[1]);}
  }

  //find max element in array b
  long int max = 0;
  rep(1,n){if(max < b[i]){max = b[i];}}

  //answer
  printf("%ld",k - max);
  return 0;
}
