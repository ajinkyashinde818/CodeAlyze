#include <string.h>
#include <stdio.h>
#define REP(i,n) for(int i=0; i< int(n); (i)++)

int main()
{
    char a[52]={0};
    int i,len,tmp;
    scanf("%s",a);
    len = strlen(a);
    REP(i,len-8)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}
