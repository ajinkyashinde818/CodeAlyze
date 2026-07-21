#include<stdio.h>
int main()
{
    char a,b,c,d;
    while(scanf("%c %c",&a,&b)!=EOF)
    {
        getchar();
        c=a-'A';
        d=b-'A';
        if(c==d)
        {
            printf("=\n");
        }
        else if(c>d)
        {
            printf(">\n");
        }
        else
        {
            printf("<\n");
        }
    }
    return 0;
}
