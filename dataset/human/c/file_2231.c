#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

int main(void){
	char s[500001];
	scanf("%s", s+200000);
	int l=200000, r=200000+strlen(s+200000);
	int f=1;

	int q, i;
	scanf("%d", &q);
	for(i=0; i<q; i++){
		int Q, F;
		char c;
		scanf("%d", &Q);
		if(Q==1){
			f=(f==1?2:1);
		}else{
			scanf("%d %c", &F, &c);
			if(F==f){
				s[--l]=c;
			}else{
				s[r++]=c;
			}
		}
	}
	if(f==1){
		s[r]=0;
		printf("%s\n", s+l);
	}else{
		for(i=r-1; i>=l; i--){
			putchar(s[i]);
		}
		putchar(10);
	}
}
