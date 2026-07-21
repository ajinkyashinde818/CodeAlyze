#include <stdio.h>

int main(void) {
	int i,s[10000],max;
	
	i = 0;
	
	while(1){
		i++;
		scanf("%d\n",&s[i]);
		if(s[i] == 0){ max = i; break;}
	}
	
	for(i=1;i<max;i++)
	printf("Case %d: %d\n",i,s[i]);
	return 0;
}
