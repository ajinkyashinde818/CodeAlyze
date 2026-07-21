#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, br=0;
    scanf("%d%d", &n, &k);
    int a[n+1];
    for(i=0; i<n; i++){
		scanf("%d", &a[i]);
    }

    for(i=0; i<n; i++){
		if(a[i]>=k) br++;
    }

    printf("%d", br);

    return 0;
}
