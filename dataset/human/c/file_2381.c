#include <stdio.h>
#include <algorithm>
#include <complex>

int main()
{
    char s[8];
    bool t[3]{};
    scanf("%s", s);
    for (int i = 0; i < 3; ++i)
        t[s[i] - 'a'] = true;
    
    if (t[0] && t[1] && t[2]) printf("Yes\n");
    else printf("No\n");

    return 0;
}
