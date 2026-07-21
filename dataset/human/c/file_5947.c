#include <stdio.h>

int main()
{
    int n, i;
    long long int R, Rmin = 1000000000, Rdmax = -1000000000;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &R);
	if (i != 0 && Rdmax < R - Rmin) 
            Rdmax = R - Rmin;
	if (R < Rmin) 
	    Rmin = R;
    }
    printf("%d\n", Rdmax);
    return 0;
}
