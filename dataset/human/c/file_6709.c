#include<stdio.h>

int main(void)
{
	int stu,list,man1,man2;
	int cut_i,cut_j,tem;
	int frn1[501],frn2[501][501];
	int ans[501];

	while(1){
		scanf("%d",&stu); 
		
		scanf("%d",&list);
		
		if((stu|list) == 0){
			break;
		}

		int kyaku = 0;

		for(cut_i=2;cut_i<501;cut_i++){
			frn1[cut_i]=0;
			ans[cut_i]=0;
			for(cut_j=2;cut_j<501;cut_j++){
				frn2[cut_i][cut_j]=0;
			}
		}

		for(cut_i=0;cut_i<list;cut_i++){
			scanf("%d%d",&man1,&man2);
			if(man1>man2){
				tem = man1;
				man1 = man2;
				man2 = tem;
			}
			if(man1 == 1){
				frn1[man2] =1;
			}
			else {
				frn2[man1][man2] =1;
				frn2[man2][man1] =1;
			}
		}

		for(cut_i=2;cut_i<500;cut_i++){
			if(frn1[cut_i] == 1){
				ans[cut_i] = 1;
				for(cut_j = 2; cut_j<501;cut_j++){
					if(frn2[cut_i][cut_j] == 1){
						ans[cut_j] = 1;
					}
				}
			}
		}
		for(cut_i = 2;cut_i < 501; cut_i++){
			kyaku+=ans[cut_i];
		}
		printf("%d\n",kyaku);
	}
	return 0;
}
