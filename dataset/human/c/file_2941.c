#include <stdio.h>

int main ()
{
    int k,s,x,y,z,b=0;
    scanf ("%d %d", &k ,&s);
    for (x=0;x<=k;x++)
        for (y=0;y<=k;y++){
            z=s-x-y;
            if (z>=0 && z<=k) 
                b++;


        }
    printf("%d", b);





    return 0;
}
