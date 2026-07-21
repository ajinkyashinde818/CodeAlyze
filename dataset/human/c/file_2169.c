#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i;
    char s[200001];
    int q;
    int t, f;
    char c;
    char prefix_[200001], suffix_[200001];
    char *prefix = prefix_, *suffix = suffix_;
    char *tmp_c;
    int tmp_d;
    int prefix_len = 0, suffix_len = 0;
    int order = 1;

    scanf("%s%d", s, &q);

    for (i = 0; i < q; i++)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            order *= -1;
            tmp_c = prefix;
            prefix = suffix;
            suffix = tmp_c;
            tmp_d = prefix_len;
            prefix_len = suffix_len;
            suffix_len = tmp_d;
        }
        else
        {
            scanf("%d %c", &f, &c);
            if (f == 1)
            {
                prefix[prefix_len] = c;
                prefix_len++;
            }
            else
            {
                suffix[suffix_len] = c;
                suffix_len++;
            }
        }
    }
    prefix[prefix_len] = '\0';
    suffix[suffix_len] = '\0';

    for (i = strlen(prefix) - 1; i >= 0; i--)
        printf("%c", prefix[i]);
    if (order == 1)
    {
        printf("%s", s);
    }
    else
    {
        for (i = strlen(s) - 1; i >= 0; i--)
            printf("%c", s[i]);
    }
    printf("%s\n", suffix);
    return EXIT_SUCCESS;
}
