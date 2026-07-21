#include <stdio.h>

int main(){
	int R, G, B, N, ans = 0, i,j,N_R,N_G,b;
  	scanf("%d %d %d %d\n", &R, &G, &B, &N);
  	N_R = N/R;
  	N_G = N/G;
  	for(i = 0; i <= N_R; i++){
    	for(j = 0; j <= N_G; j++){
          b = N - R*i - G*j;
            	if(b % B == 0 && b >= 0){
                	ans++;
                }
        }
    }
  	printf("%d\n",ans);
}
