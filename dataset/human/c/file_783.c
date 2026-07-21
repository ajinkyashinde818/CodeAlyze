#include <stdio.h>
#include <string.h>

int main(void)
{
	//変数の宣言
	int d,g;
	int p[10];
	int c[10];
	int total[10];
	int sum,sum1;
	int mondaisu,mondaisu1;
	int min=1000;
	int i,j,k;
	
	//データの読み込み
	
	scanf("%d %d",&d,&g);
	
	for(i=0;i<d;i++){
		scanf("%d %d",&p[i],&c[i]);
	}
	
//	printf("nは%dです\n", n);
//	printf("データの読み込み終了\n");
	//実際の処理
	
	for(i=0;i<d;i++){
		total[i]=p[i]*(i+1)*100+c[i];
	}
	
//	printf("100点問題を全部とくと%d点",total[0]);
	
	for(i=0;i<(1<<d);i++){
//		printf("i=%dのループ開始\n",i);
		sum=0;
		mondaisu=0;
		for(j=0;j<d;j++){
//			printf("i=%d,1<<j=%d,i&(1<<j)=%d\n",i,1<<j,i&1<<j);
			if(i&(1<<j)){
//				printf("%d00点問題は解く\n",i);
				sum=sum+total[j];
				mondaisu=mondaisu+p[j];
			}
		}
		
//		printf("sum=%d\n",sum);
		
		if(sum<g){
			for(j=0;j<d;j++){
//				printf("OK1\n");
				if(~i&(1<<j) && sum+total[j]+1>g){
					k=0;
					sum1=sum;
					mondaisu1=mondaisu;
					
//					printf("sum=%d\n",sum);
					
					for(k=1;k<p[j]+1;k++){
//						printf("OK4 %d回目のループ\n",k);
						mondaisu1++;
						sum1=sum1+(j+1)*100;
//						printf("sum1=%d,g=%d,k=%d,p[j]=%d,mondaisu1=%d\n",sum1,g,k,p[j],mondaisu1);
						if(sum1+1>g || k==p[j]){
//							printf("breakします");
							break;
						}else{
//							printf("もう一周\n");
						}
					}
					
//					printf("i=%d,解いた問題数=%d\n",i,mondaisu1);
					
					if(mondaisu1<min){
						min=mondaisu1;
					}
				}
			}
		}
	}
	
	
//	printf("計算部分終了\n");
	
	//出力
	
	printf("%d\n",min);
	
//	printf("結果の出力終了\n");

	return 0;
}
