#include <stdio.h>
#define N 200000

int main() {

	int n,i,j,p[N],pi_min,p_MAX;

	scanf("%d",&n);

	for (i = 0; i < n; i++) scanf("%d", &p[i]);

	pi_min = p[0];

	for (i = 0; i < n-1; i++) {
		if (p[i] > pi_min) continue;

		else pi_min = p[i];

		for (j = i+1; j < n; j++) {
			if (i == 0 && j == 1) p_MAX = p[j] - p[i];	//最初の初期化	

			if (p_MAX < p[j] - p[i]) p_MAX = p[j] - p[i];
						
		}
		
	}

	printf("%d\n",p_MAX);

	return 0;

}
