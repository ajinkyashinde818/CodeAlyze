#include <stdio.h>

int D,G;
int p[10];
int c[10];
#define pow2(n) (1 << n)
//int pow2(int n)  { return 1 << n;}

int main(){
	scanf("%d %d",&D,&G);
	for(int i = 0; i < 10; i++){
		p[i] = c[i] = 0;
	}
	for(int i = 0; i < D; i++){
		scanf("%d %d",p+i,c+i);
	}

	int mincnt = 100000;
	for(int n = 0; n < pow2(D); n++){
		int cnt = 0;
		int score = 0;
		// complete block
		for(int i = 0; i < D; i++){
			if(n & pow2(i)){
				score += c[i] + (i+1)*100*p[i];
				cnt   += p[i];
			}
		}	
		// non-complete block

		for(int i = D-1; i >= 0; i--){
			if(n & pow2(i) || p[i]==0) continue;

			if(G-score > (i+1)*100*(p[i]-1)){
				score += (i+1)*100*(p[i]-1);
				cnt   += p[i]-1;
			}else{
				if(G >= score){
					if( (G-score) % ((i+1)*100) == 0)
						cnt += (G-score)/ ((i+1)*100);
					else
						cnt += 1 + (G-score)/ ((i+1)*100);
					score += cnt*((i+1)*100);
				}else {}
				break;
			}
		}
		if(G > score) cnt = 10000;
		//printf("(n=%d, cnt=%d)\n",n,cnt);
		if (mincnt > cnt) mincnt = cnt;
	}
	printf("%d\n",mincnt);
}
