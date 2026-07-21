#include <stdio.h>
    #include <stdlib.h>
     
    int main() {
      
      int import = 0;
      
      scanf("%d", &import);
      
      int ten = import / 10;
      
      
      if( (import - 90) >= 0) {
        printf("Yes");
       } else if( (import - (ten*10)) == 9) {
         printf("Yes");
       } else {
         printf("No");
       }
      
      return 0;
    }
