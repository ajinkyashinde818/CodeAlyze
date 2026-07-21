#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{
	int a, i, j, smin, tmax, slen, tlen, count, temp, countans = 0;
	char s[101],t[101];
	a = scanf("%s", s);
	a = scanf("%s", t);
	slen = strlen(s);
	tlen = strlen(t);
	smin = s[0];
	tmax = t[0];
	for(i = 1; i < slen; i++){
		if(smin > s[i])
			smin = s[i];
	}
	for(i = 1; i < tlen; i++){
		if(tmax < t[i])
			tmax = t[i];
	}
	if(smin < tmax)
		printf("Yes");
	else if(smin > tmax)
		printf("No");
	else{
		if(slen >= tlen){
			printf("No");
		}
		else{
			for(i = 1; i < slen; ++i)
				for(j = slen; j >= i; --j){
					if(s[j-1] > s[j]){
						temp = s[j-1];
						s[j-1] = s[j];
						s[j] = temp;
					}
				}
			for(i = 1; i < tlen; ++i)
				for(j = tlen; j >= i; --j){
					if(t[j-1] < t[j]){
						temp = t[j-1];
						t[j-1] = t[j];
						t[j] = temp;
					}
				}
			for(i = 1; i < slen; i++){
				if(s[i] > t[i]){
					printf("No");
					countans = 1;
					break;
				}
			}
			if(countans == 0)
				printf("Yes");
		}
	}
	return 0;		
}
