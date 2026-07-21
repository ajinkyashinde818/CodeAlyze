#include <stdio.h>

int main() {
    int a,b,k;
    scanf("%d %d %d", &a, &b, &k);
  int count=0;
  int i;
  int large = a;
  if(large<b){large = b;}
  for(i=large;i>0;i--){
    if(a%i==0){
      if(b%i==0){
        count++;
        if(count==k){
          break;
        }
      }
    }
  }
    printf("%d", i);
    return 0;
}
