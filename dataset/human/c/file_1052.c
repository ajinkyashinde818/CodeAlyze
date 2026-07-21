#include<stdio.h>
#define MAX 50

int main()
{
        char str[MAX];
        int i;
        int cnt;

        scanf("%s", str);

        for(cnt=0; str[cnt]!='\0'; cnt++);

        for(i=0; i<cnt-8; i++)printf("%c", str[i]);
        printf("\n");

        return 0;
}
