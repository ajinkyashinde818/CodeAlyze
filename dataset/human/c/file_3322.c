#include <stdio.h>
#include <string.h>

int main()
{
	char s[100010];
	int i, c;

	scanf("%s", s);

	i = 0;
	while(s[i]){
		if(s[i] == 'd'){
			if(s[i+1] == 'r'&& s[i+2] == 'e' && s[i+3] == 'a' && s[i+4] == 'm') i = i+5;
			else break;
		}
		else if(s[i] == 'e'){
			if(s[i+1] == 'r' && s[i+2] == 'a'){
				if(s[i+3] == 's' || s[i+4] == 'e') i = i+5;
				else break;
			}
			else{
				if(s[i-1] == 'm' && s[i+1] == 'r') i = i + 2;
				else break;
			}
		}
		else{
			if(s[i] == 'r' && s[i-1] == 'e') i = i + 1;
			else break;
		}
	}

	if(s[i]) printf("NO");
	else printf("YES");

return 0;
}
