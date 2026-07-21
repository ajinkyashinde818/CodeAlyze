#include <stdio.h>

int t[110], n, m, min;

void solve (int l, int r)
{
	int i, i2, ts;
	i2 = 0;
	ts = 0;
	i = 0;
	
	if (l > r){
		return;
	}
	
	
	while (i < m){
		
		ts += t[i2];
		i2++;
		if (ts == (l + r) / 2){
			i++;
			ts = 0;
		}
		else if (ts > (l + r) / 2){
			i2--;
			i++;
			ts = 0;
		}
		if (i2 == n){
			break;
		}
	}
	if (i2 == n){
		if (min > (l + r) / 2){
			min = (l + r) / 2;
		}
		solve(l, (l + r) / 2 - 1);
	}
	else{
		solve((l + r) / 2 + 1, r);
	}
}
	
	

int main(void)
{
	int i;
	
	while (1){
		
		scanf("%d %d", &m, &n);
		min = 1500050;
		
		if (m == 0 && n == 0){
			break;
		}
		
		for (i = 0; i < n; i++){
			scanf("%d", &t[i]);
		}
		solve(0, 1500000);
		printf("%d\n", min);
	}
	return (0);
}
