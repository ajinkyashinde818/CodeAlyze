#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    while (n > 0)
    {
        if (s[0] == 'd' && s[1] == 'r'&& s[2] == 'e' && s[3] == 'a' && s[4] == 'm')
        {
            if (s[5] == 'e' && s[6] == 'r' && s[7] != 'a')
            {
                for (i = 0; i < n - 7; i++)
                    s[i] = s[i + 7];
                for (i = n - 7; i < n; i++)
                    s[i] = '0';
                n -= 7;
            }
            else
            {
                for (i = 0; i < n - 5; i++)
                    s[i] = s[i + 5];
                for (i = n - 5; i < n; i++)
                    s[i] == '0';
                n -= 5;
            }
        }
        else if (s[0] == 'e' && s[1] == 'r' && s[2] == 'a' && s[3] == 's' && s[4] == 'e')
        {
            if (s[5] == 'r' && s[6] != 'a')
            {
                for (i = 0; i < n - 6; i++)
                    s[i] = s[i + 6];
                for (i = n - 6; i < n; i++)
                    s[i] = '0';
                n -= 6;
            }
            else
            {
                for (i = 0; i < n - 5; i++)
                    s[i] = s[i + 5];
                for (i = n - 5; i < n; i++)
                    s[i] = '0';
                n -= 5;
            }
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
