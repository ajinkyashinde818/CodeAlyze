#include<stdio.h>


int main()
{



   // scanf("%s", &s);

    int n, k;

    scanf("%d", &n);

    char s[n+2];

    scanf("%s", &s);

    scanf("%d", &k);

    char ch = s[k-1];


    for(int i = 0; i < n; i++)
    {
        if(s[i] != ch)
        {
            s[i] = '*';
        }
    }

    printf("%s", s);




    return 0;
}
