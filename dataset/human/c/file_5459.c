#include <stdio.h>

int main(void)
{
	int W, H, N;
	int w, h;
	int fx, fy;
	int tx, ty;
	int i;
	int sum;
	
	
	scanf("%d%d%d", &W, &H, &N);

	sum = 0;
	scanf("%d%d", &fx, &fy);
	for (i = 1; i < N; i++){
		scanf("%d%d", &tx, &ty);

		if (fx > tx){
			w = fx - tx;
		}
		else {
			w = tx - fx;
		}
		if (fy > ty){
			h = fy - ty;
		}
		else {
			h = ty - fy;
		}

		if ((fy < ty && fx < tx) || (fy > ty && fx > tx)){
			if (h > w){
				sum += h;
			}
			else {
				sum += w;
			}
		}
		else {
			sum += (h + w);
		}
		fx = tx;
		fy = ty;
	}
	
	printf("%d\n", sum);
	
	return (0);
}
