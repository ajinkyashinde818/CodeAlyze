#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100005],revs[1000005];
    scanf("%s", s);
    int n=0,i;
    while(strncmp(&s[n], "\0", 1)!=0) n++;

    for(i=0; i<n; i++) revs[i]=s[n-i-1];
    i=0;
    while(i!=n)
    {
        if(strncmp(revs+i, "maerd",5)==0) i+=5;
        else if(strncmp(revs+i, "remaerd",7)==0) i+=7;
        else if(strncmp(revs+i, "esare",5)==0) i+=5;
        else if(strncmp(revs+i, "resare",6)==0) i+=6;
        else
        {
            printf("NO");
            break;
        }
    }
    if(i==n) printf("YES");
    return 0;
}
