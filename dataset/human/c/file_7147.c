#include <stdio.h>
 
int main(void)
{
    int w, h, i, j;
 
    while(scanf("%d %d", &h, &w), h+w)
    {
        for(j=0; j<h; j++)
        {
            for(i=0; i<w; i++)
                printf(((i+j)%2)? ".": "#");
 
            puts("");
        }
 
        puts("");
    }
 
    return 0;
}
