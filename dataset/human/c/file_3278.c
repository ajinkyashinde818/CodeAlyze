#include <stdio.h>
#define MAX_N 200000
int max(a, b){
  if (a>b)return a;
  else return b;
}
int i;
int main(){
  int n, k;
  int t;
  int longest=-1;
  scanf("%d %d", &k, &n);
  int a[MAX_N];
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
    if(i>0){
      longest = max(longest, a[i]-a[i-1]);
    }
  }
  t = a[0]-(a[n-1]-k);
  longest = max(longest, t);
  printf("%d", k-longest);
  printf("\n");
}
