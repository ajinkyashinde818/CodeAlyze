#include <stdio.h>
#include <math.h>

int main(void)
{
	int table[8] = {1, 4, 1, 2, 1, 2, 1, 4};
	int user[8];

	while (~scanf("%d", user)){
		int i, offset, minv, maxu;

		for (i = 1; i < 8; i++){
			scanf("%d", user + i);
		}
		
		minv = 9e8;
		maxu = offset = 0;
		for (i = 0; i < 8; i++){
			int j, v, u;
			u = v = 0;
			for (j = 0; j < 8; j++){
				int t = table[(j + i) % 8];
				v = v * 10 + t;
				u += fmin(t, user[j]);
			}
			if (maxu < u){
				offset = i;
				maxu = u;
				minv = v;
			} 
			else if (maxu == u){
				if (minv > v){
					offset = i;
					minv = v;
				}
			}
		}
		for (i = 0; i < 8; i++){
			printf("%d%c", table[(i + offset) % 8], i == 7 ? '\n' : ' ');
		}
	}
	return (0);
}
