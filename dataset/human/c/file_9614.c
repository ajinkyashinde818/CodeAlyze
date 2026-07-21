#include <stdio.h>

int main(void) {
	int hit_num;
	char hit_numbers[100][12];
	int hit_money[100];
	int get_money;
	char input_number[12];
	int input_num;
	int i,j,k;
	while(1) {
		scanf("%d%d",&hit_num,&input_num);
		if(hit_num==0)break;
		for(i=0;i<hit_num;i++) {
			scanf("%s%d",hit_numbers[i],&hit_money[i]);
		}
		get_money=0;
		for(i=0;i<input_num;i++) {
			scanf("%s",input_number);
			for(j=0;j<hit_num;j++) {
				for(k=0;k<8;k++) {
					if(hit_numbers[j][k]!='*' &&
						hit_numbers[j][k]!=input_number[k])break;
				}
				if(k>=8) {
					get_money+=hit_money[j];
					break;
				}
			}
		}
		printf("%d\n",get_money);
	}
	return 0;
}
