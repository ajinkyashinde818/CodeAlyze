#include <stdio.h> 
int main()
{
	int n, mini, res, r, i;
    scanf("%d%d%d", &n, &mini, &r);
	res = r - mini;
    if(r < mini) mini = r;
	for (i = 2; i < n; i++) {
        scanf("%d", &r);
        if(r - mini > res) res = r - mini;
        if(r < mini) mini = r;
	}
    printf("%d\n", res);
	return 0;
}
