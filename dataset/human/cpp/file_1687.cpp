#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n, i;
  scanf("%d", &n);
  for(i = 2; i*(i-1)/2 <= n; i++){
    if(i*(i-1)/2 == n) break;
  }
  if(i*(i-1)/2 == n){
    printf("Yes\n%d\n", i);
    for(int j = 0; j < i; j++){
      printf("%d", i-1);
      int t = j;
      for(int k = 0; k < j; k++){
        printf(" %d", t);
        t += i-2-k;
      }
      t = (2*i-1-j)*j/2 + 1;
      for(int k = 0; k < i-1-j; k++) printf(" %d", t+k);
      printf("\n");
    }
  }else printf("No\n");
}
