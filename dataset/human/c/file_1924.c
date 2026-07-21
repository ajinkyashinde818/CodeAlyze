#include <stdio.h>

typedef struct
{
    int b;
    int c;
}food;


int main (void){
    int n = 0;
    int a[20] = {0};
    food meal[20];
    int h =0;

    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&meal[i].b);
    }

    for (int i = 0; i < n-1; i++)
    {
        scanf("%d",&meal[i].c);
    }

    for (int i = 0; i < n; i++)
    {
        h+=meal[a[i]-1].b;

        if (a[i+1]==(a[i]+1))
        {
            h+=meal[a[i]-1].c;
        }
        
    }
    
    printf("%d",h);

    return 0;

}
