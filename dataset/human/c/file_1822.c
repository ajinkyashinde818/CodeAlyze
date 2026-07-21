#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum=0;
    int a[1000], b[1000], c[1000];
    scanf("%d", &n);
    for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
    }
    for(i=1; i<=n; i++){
		scanf("%d", &b[i]);
		sum+=b[i];
    }
    for(i=1; i<n; i++){
		scanf("%d", &c[i]);
    }

    for(i=1; i<n; i++){
		if(a[i+1]-a[i]==1)
			sum+=c[a[i]];
    }

    printf("%d", sum);

    return 0;
}
