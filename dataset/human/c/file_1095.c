#include <stdio.h>
#include <ctype.h>

int to_i[128];

int mcxi2int(char *s)
{
    int i, d=1, res=0;
    for(i=0;s[i];++i) {
        if (isdigit(s[i])) {
            d=s[i]-'0';
        }
        else {
            res+=to_i[s[i]]*d;
            d=1;
        }
    }
    return res;
}
int main(void)
{
    int n;
    char *s="mcxi";
    scanf("%d", &n);
    to_i['m']=1000, to_i['c']=100, to_i['x']=10, to_i['i']=1;
    while (n--) {
        char a[10], b[10];
        int c, d, i;
        scanf("%s%s", a, b);
        c=mcxi2int(a)+mcxi2int(b);
        d=1000;
        for(i=0;i<4;++i,c%=d,d/=10) {
            int t=c/d;
            if (t) {
                if (t>1) printf("%d", t);
                putchar(s[i]);
            }
        }
        puts("");
    }
    return 0;
}
