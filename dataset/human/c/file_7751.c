#include<stdio.h>

main()
{
	int N,K,P,cou1,cou2;
	
	scanf("%d",&N);
	
	for(cou1=1;cou1<=N;cou1++){
		scanf("%d %d",&K,&P);
		
		while(K>0){
			for(cou2=1;cou2<=P;cou2++){
				K--;
				if(K==0){
					break;
				}
			}
		}
		printf("%d\n",cou2);
	}
	
	return 0;
}
