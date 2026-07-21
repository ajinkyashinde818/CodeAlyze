#include <stdio.h>
int main()
{   char x[2],y[2];
    scanf("%s%s",x,y);
    if((x[0]-'A')>(y[0]-'A')){
        printf(">");
    }else if((x[0]-'A')==(y[0]-'A'))
    printf("=");
    else printf("<");
    return 0;
}
