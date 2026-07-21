#include<stdio.h>
int main(){
	char S[3];
	scanf("%s", S);
	if (S[0] == 'a'){
		if (S[1] == 'a'){
			printf("No");
		}
		else if (S[1] == 'b'){
			if (S[2] == 'c'){
				printf("Yes");
			}
			else printf("No");
		}
		else if (S[1] == 'c'){
			if (S[2] == 'b'){
				printf("Yes");
			}
			else printf("No");
		}
	}
	else if (S[0] == 'b'){
		if (S[1] == 'a'){
			if (S[2] == 'c'){
				printf("Yes");
			}
			else printf("No");
		}
		else if (S[1] == 'b'){
			printf("No");
		}
		else if (S[1] == 'c'){
			if (S[2] == 'a'){
				printf("Yes");
			}
			else printf("No");
		}
	}
	else if (S[0] == 'c'){
		if (S[1] == 'a'){
			if (S[2] == 'b'){
				printf("Yes");
			}
			else printf("No");
		}
		else if (S[1] == 'c'){
			printf("No");
		}
		else if (S[1] == 'b'){
			if (S[2] == 'a'){
				printf("Yes");
			}
			else printf("No");
		}
	}
	return (0);
}
