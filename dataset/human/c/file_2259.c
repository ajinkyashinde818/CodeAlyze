#include <stdio.h>
#include <string.h>

short getshortest(short a, short b, short c)
{
	if (a <= b && a <= c){
		return (a);
	}
	else if (b <= c && b <= a){
		return(b);
	}
	return(c);
}

int main(void)
{
	char map[1000][1000];
	static short sq[1000][1000];
	int i, j;
	int n;
	int max;
	
	while (1){
		scanf("%d", &n);
		
		if (!n){
			break;
		}
		
		for (i = 0; i < n; i++){
			memset(map[i], '\0', sizeof(map[i]));
			memset(sq[i], 0, sizeof(sq[i]));
			scanf("%s", map[i]);
		}
		
		max = 0;
		
		for (i = 0; i < n; i++){
			sq[i][0] = map[i][0] == '.' ? 1 : 0;
			sq[0][i] = map[0][i] == '.' ? 1 : 0;
			if (sq[i][0] == 1 || sq[0][i] == 1){
				max = 1;
			}
		}
		
		for (i = 1; i < n; i++){
			for (j = 1; j < n; j++){
				if (map[i][j] == '*'){
					sq[i][j] = 0;
				}
				else {
					sq[i][j] = getshortest(sq[i][j - 1], sq[i - 1][j], sq[i - 1][j - 1]) + 1;
					if (sq[i][j] > max){
						max = sq[i][j];
					}
				}
			}
		}
		printf("%d\n", max);
	}
	
	return (0);
}
