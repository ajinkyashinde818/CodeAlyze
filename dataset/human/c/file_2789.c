#include<stdio.h>
#include<math.h>

int main(){
	int k, s, a, b, c,cnt=0;
	scanf("%d%d", &k, &s);
	for (a = 0; a <= k; a++)
		for (b = 0; b <= k; b++) {
			c = s - a - b;
			if (0 <= c && c <= k)
				cnt++;
		}
			

	printf("%d", cnt);
	return 0;

}
