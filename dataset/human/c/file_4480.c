#include<stdio.h>
int main(void){
	int n,d_1,d_2;
	int cnt=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&d_1,&d_2);
		if(cnt){
			if(d_1==d_2){
				cnt++;
			}
			else{
				cnt=0;
			}
		}
		else{
			cnt+=d_1==d_2;
		}
		if(3<=cnt){
			break;
		}
	}
	printf(3<=cnt?"Yes":"No");
	return 0;
}
