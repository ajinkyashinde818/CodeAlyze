#include <stdio.h>
#include <string.h>

void sort1(char *s, int n);
void sort2(char *s, int n);

int main(void)
{
    int ns, nt;
    char s[101], t[101];

    scanf("%s", s);
    scanf("%s", t);

    ns = strlen(s);
    nt = strlen(t);

    sort1(s, ns);
    sort2(t, nt);

    if (strcmp(s,t)<0)  printf("Yes\n");
    else                printf("No\n");

    return 0;
}

void sort1(char *s, int n)
{
    int i, j, m;
    char tmp;

    for (i=0; i<n-1; i++) {
        m = i;
        for (j=i+1; j<n; j++) {
            if (s[j]<s[m])  m=j;
        }
        tmp=s[i]; s[i]=s[m]; s[m]=tmp;
    }
}

void sort2(char *s, int n)
{
    int i, j, m;
    char tmp;

    for (i=0; i<n-1; i++) {
        m = i;
        for (j=i+1; j<n; j++) {
            if (s[j]>s[m])  m=j;
        }
        tmp=s[i]; s[i]=s[m]; s[m]=tmp;
    }
}
