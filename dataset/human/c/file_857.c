#include <stdio.h>
#include <math.h>


int main()
{		
	long long n;
	int i, k, ans = 0, x, c, t;
	
	scanf("%lld", &n);
	for(i = 2, k = sqrt(n); i <= k; i++){
		if(n % i) continue;
		x = 0;
		do{
			n /= i;
			x++;
		}while(n % i == 0);
		k = sqrt(n);
		t = 1, c = 1;
		while(1){
			t += c + 1;
			if(t > x) break;
			c++;
		}
		ans += c;
	}
	if(n > 1) ans++;
	printf("%d\n", ans);
				
	return 0;
}
