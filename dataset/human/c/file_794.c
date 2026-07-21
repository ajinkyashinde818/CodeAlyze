#include <stdio.h>

int main(void){
	int D,G,ans=1e9,i;
	scanf("%d %d",&D,&G);
	int p[D+1],c[D+1];
	for(i=1;i<=D;i++)scanf("%d %d",&p[i],&c[i]);
	int list;
	//num << n でnumが2^n倍される
	//1 << D = 2^D
	for(list=0; list<(1<<D); list++){
		int score=0, num=0, rest_max;
		for(i=1; i<=D; i++){
			if(list>>(i-1) & 1){
			//listを左にiビットシフトし、1とのビット論理和
			//=> listの2進数表記のi桁目が１なら解く
				score += 100*i*p[i] + c[i];
				num += p[i];
			}
			else{
				rest_max = i;//解いていない
			}
		}
		if(score<G){
			int s1 = 100*rest_max;//中途半端に解く問題の点数
			int need = (G-score+s1-1)/s1;
			if(need > p[rest_max]) continue;//以下を実行せず次のループへ
			num += need;
		}
		ans = ans<num? ans: num;	
	}
	printf("%d",ans);	
	return 0;
}
