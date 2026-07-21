#include <stdio.h>

int main(void)
{
  int h;
  int w;

  while(1){
    scanf("%d %d", &h, &w);
      if(h == 0 && w == 0){
      break;
    }

    for(int x = 1; x <= h; x = x + 1){//xは何段目かを示す                                                                                                                            

      if(x < h){
        if(x % 2 == 1){
          for(int n = 1; n <= w;n = n + 1){
            if(n % 2 == 1 && n != w){
              printf("#");
            }
            else if(n % 2 == 1 && n == w){
              printf("#\n");
            }
            else if(n % 2 == 0 && n != w){
              printf(".");
            }
            else if(n % 2 == 0 && n == w){
              printf(".\n");
            }
          }
        }
        else{
          for(int n = 1; n <= w;n = n + 1){
            if(n % 2 == 1 && n != w){
              printf(".");
            }
            else if(n % 2 == 1 && n == w){
              printf(".\n");
            }
            else if(n % 2 == 0 && n != w){
              printf("#");
            }
            else if(n % 2 == 0 && n == w){
              printf("#\n");
            }
          }
        }
      }
      if(x == h){
        if(h % 2 == 1){
          for(int n = 1; n <= w;n = n + 1){
            if(n % 2 == 1 && n != w){
              printf("#");
            }
            else if(n % 2 == 1 && n == w){
              printf("#\n");
              printf("\n");
            }
            else if(n % 2 == 0 && n != w){
              printf(".");
            }
            else if(n % 2 == 0 && n == w){
              printf(".\n");
              printf("\n");
            }
          }
        }
        else if(h % 2 == 0){
          for(int n = 1; n <= w;n = n + 1){
            if(n % 2 == 1 && n != w){
              printf(".");
            }
            else if(n % 2 == 1 && n == w){
              printf(".\n");
              printf("\n");
            }
            else if(n % 2 == 0 && n != w){
              printf("#");
            }
            else if(n % 2 == 0 && n == w){
              printf("#\n");
              printf("\n");
            }
          }
        }
      }
    }
  }
  return 0;
}
