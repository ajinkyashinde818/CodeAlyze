#include <stdio.h>
int main(void){
	int w,h,n,c,i,d='#'^'.';
	for(;scanf("%d%d",&h,&w),h;puts(""))
		for(n='#';h--;n^=d,puts(""))
			for(i=w,c=n;i--;c^=d)putchar(c);
	return 0;
}
