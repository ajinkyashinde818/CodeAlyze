#include <stdio.h>

int main(void)
{
    int E, Y;
    
    scanf("%d%d", &E, &Y);
    
    switch (E){
      case 0:
        if (Y <= 1911){
            printf("M%d\n", Y - 1867);
        }
        else if (Y <= 1925){
            printf("T%d\n", Y - 1911);
        }
        else if (Y <= 1988){
            printf("S%d\n", Y - 1925);
        }
        else{
            printf("H%d\n", Y - 1988);
        }
        break;
      
      case 1:
        printf("%d\n", Y + 1867);
        break;
      
      case 2:
        printf("%d\n", Y + 1911);
        break;
      
      case 3:
        printf("%d\n", Y + 1925);
        break;
      
      case 4:
        printf("%d\n", Y + 1988);
        break;
    }

    return (0);
}
