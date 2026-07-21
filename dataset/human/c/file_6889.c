// AOJ 2525: Change
// 2017.10.6 bal4u@uu

#include <stdio.h>

int main()
{
	int rd, rr;
    long long m, cd, cr, s, t;
 
	scanf("%lld%d%d%lld%lld", &m, &rd, &rr, &cd, &cr);
    s = cd * 100 / rd;
    if (cd * 100 % rd) s++;
    t = cr * 100 / rr;
    if (cr * 100 % rr) t++;
    if (m-s-t < 0) puts("-1");
	else printf("%lld\n", m-s-t);
    return 0;
}
