#include <stdio.h>
#include <string.h>


int main(void)
{
	char s[101];
	char t[1001];
	int soe;
	int i = 1;
	int tmp;
	
	scanf("%s", s);
	scanf("%s", t);
	
	while (i != 0){
		i = 0;
		for (soe = 1; s[soe] != '\0'; soe++){
			if (s[soe - 1] > s[soe]){
				tmp = s[soe];
				s[soe] = s[soe - 1];
				s[soe - 1] = tmp;
				i++;
			}
		}
	}
	
	
	i = 1;
	while (i != 0){
		i = 0;
		for (soe = 1; t[soe] != '\0'; soe++){
			if (t[soe - 1] < t[soe]){
				tmp = t[soe];
				t[soe] = t[soe - 1];
				t[soe - 1] = tmp;
				i++;
			}
		}
	}
	if (strcmp(t, s) > 0){
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	
		
	return (0);
}
