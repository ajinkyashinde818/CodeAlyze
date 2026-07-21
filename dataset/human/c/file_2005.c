#include <stdio.h>

int main()
{
    unsigned int a_undelic = 0, b_delic = 0, c_delicp = 0;
    unsigned int tmp_cookie = 0, total = 0;

    scanf("%d %d %d", &a_undelic, &b_delic, &c_delicp);
    total = c_delicp + b_delic;

    if ((b_delic + a_undelic) >= c_delicp) {
        total -= tmp_cookie;
    } else {
    	tmp_cookie = c_delicp - b_delic;
    	tmp_cookie -= a_undelic + 1;
    	total -= tmp_cookie;
    }
	printf("%d\n",total);
    return 0;
}
