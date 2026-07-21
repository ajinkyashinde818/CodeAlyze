#include <stdio.h>

int main(void){
	int cnt;
	long long int s;
	while(1){
		scanf("%lld" , &s);
		if(s==0) break;
		cnt = 0;
		while(s!=1){
			if(s%2==0) s /= 2;
			else s = s*3 + 1;
			cnt++;
		}
		printf("%d\n" , cnt);
	}
	return 0;
}
