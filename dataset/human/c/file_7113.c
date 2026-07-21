#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main( void )
{

        int h = 0;
        int i = 0;
        int j = 0;
        int w = 0;

        for(;;)
        {
                scanf("%d %d", &h, &w);

                if(h == 0 && w == 0)
                {
                        break;
                }

                for(i = 0; i < h; i++)
                {
                        for(j = 0; j < w; j++)
                        {
                                if((i+j)%2 == 0)
                                {
                                        printf("#");
                                }
                                else
                                {
                                        printf(".");
                                }
                        }
                        printf("\n");
                }
                printf("\n");
        }
        return 0;
}
