#include <stdio.h>
#include <math.h>

int main(){
	int R,G,B,n;
	scanf("%d %d %d %d",&R,&G,&B,&n);
	int ans = 0;
	for (int r = 0; r <= n;r++){
		for (int g = 0;g <= n;g++){
			double b = (n - r*R - g*G)/(double)B;
			double dumy = floor(b);
			if ((b >= 0) && (b == dumy)){
				ans += 1;
			}
		}
	}
	printf("%d\n",ans);
}
