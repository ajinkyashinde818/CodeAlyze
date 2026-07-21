#include <stdio.h>
#include <string.h>

int main (void){

    int k,n;
    int sum = 0;

    scanf("%d", &k);
    scanf("%d", &n);

    for(int x = 0; x <= k; x++){
      for(int y = 0; y <= k; y++){
            
            if(0 <= n-x-y && n-x-y <= k)
              sum++;

      }
    }

    printf("%d", sum);
    return 0;
}
