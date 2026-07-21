#include <stdio.h>

int min(int a,int b){
	if (a>b){
		return b;
	}
	return a;
}

int main(void){
	int D,G,p[11],c[11];
	scanf("%d %d",&D,&G);
	int i;
	for(i=0;i<D;i++){
		scanf("%d %d",&p[i],&c[i]);
	}
	int ans = 1e9;
	for(int mask=0;mask<(1<<D);++mask){	// 1<<Dはより2^D回繰り返すってワケ。
		int s=0,num=0,rest_max=1;//rest_maxは残った問題のうちもっとも得点の高いヤツ。
		
		for(i=0;i<D;++i){		//問題の個数分このループを回す。ここは全て解く問題を選んでいる。
			if(mask>>i & 1){	//論理積をとっている。maskの分だけiをbitずらした場合論理積が1になる。
				s += 100* (i+1) * p[i] + c[i];//sは獲得した点数。
				num += p[i];	//numは解いた問題の数、解いた問題の数を加算している。
			}else{
				rest_max = i;	//iは解いていない中で最も配点の高い問題
			}
		}
		
		if(s<G){//もしも点数が上で足りていない場合以下を実行する。
			int s1 = 100*(rest_max + 1);//s1というのは解いていない中で最も配点が高い問題を解いた時の点数(ボーナスは含めない)
			int need = (G-s+s1-1)/s1;//必要な問題数は点数の残りを最高の問題で割って切り上げた数
			if(need > p[rest_max]){//問題数が足りず届かない場合は
				continue;//次のforループに向かう。
			}
			num += need;
		}
		ans = min(ans,num);
	}
	printf("%d",ans);
	return 0;
}
