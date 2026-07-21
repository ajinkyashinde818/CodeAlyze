#include <stdio.h>

int main(void)
{
	char s[10000];
	int n,k,i,j;
	
	scanf("%d %s %d",&n,s,&k);
	
	char rep;
	i=0;
	while(s[i] != '\0'){
		//printf("%d:%c\n",i+1,s[i]);
		if(i == k-1){
			rep = s[i];
			j=0;
			while(s[j] != '\0'){
				if(s[j] != rep){
					s[j] = '*';
				}
				j++;
			}
		}
		i++;
	}
	printf("%s\n",s);
	
	return 0;
}
