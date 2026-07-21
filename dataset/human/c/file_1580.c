#include<stdio.h>
char a[]={'A','B','C','D','E','F'};
char b[2];
int main()
{
    int i=0,j=0;
    scanf("%c %c",&b[0],&b[1]);
    getchar();
    while(a[i]!='\0')
    {
        if(b[0]==a[i])
        {
            break;
        }
        i++;
    }
    i=i+1;
    while(a[j]!='\0')
    {
        if(b[1]==a[j])
        {
            break;
        }
        j++;
    }
    j=j+1;
    if(i>j)
    {
        printf(">\n");
    }
    else if(i==j)
    {
        printf("=\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}
