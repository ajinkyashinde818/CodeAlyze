#include <stdio.h>

int hondana_dansuu;
int book_num;
int book_atusa[100];

int is_possible(int width) {
	int now_dansuu;
	int now_width;
	int i;
	now_width=0;now_dansuu=1;
	for(i=0;i<book_num;i++) {
		now_width+=book_atusa[i];
		if(now_width>width) {
			now_width=book_atusa[i];
			if(now_width>width)return 0;
			now_dansuu++;
		}
	}
	return (now_dansuu<=hondana_dansuu)?1:0;
}

int main(void) {
	int i;
	int left,right,mid;
	while(1) {
		scanf("%d%d",&hondana_dansuu,&book_num);
		if(hondana_dansuu==0 && book_num==0)break;
		for(i=0;i<book_num;i++) {
			scanf("%d",&book_atusa[i]);
		}
		left=1;right=1500000;
		while(left<=right) {
			mid=(left+right)/2;
			if(is_possible(mid)) {
				right=mid-1;
			} else {
				left=mid+1;
			}
		}
		printf("%d\n",right+1);
	}
	return 0;
}
