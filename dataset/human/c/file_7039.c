#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
   int height, width, x, y;
   while(scanf("%d %d", &height, &width), height && width){

      for (y = 0; y < height; y++) {
         for (x = 0; x < width; x++) {
            printf("%c", (x + y) % 2 ? '.' : '#');
         }
         printf("\n");
      }
      printf("\n");
   }
   return 0;
}
