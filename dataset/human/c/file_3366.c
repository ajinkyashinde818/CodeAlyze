#include <stdio.h>
#include <stdlib.h>

int main(){
	char *string;
	string = (char *)malloc(sizeof(char)*100002);
	scanf(" %s", string);
	int i = 0, j, k, result = 1, limit = 0;
	while(string[i] != '\0'){
		if(string[i+0] == 'd'){
			if(string[i+1] == 'r' && string[i+2] == 'e' && string[i+3] == 'a' && string[i+4] == 'm'){
				if(string[i+5] == 'd' || string[i+5] == '\0'){
					i += 5;
				}
				else if(string[i+5] == 'e' && string[i+6] == 'r'){
					if(string[i+7] == '\0' || string[i+7] == 'e' || string[i+7] == 'd'){
						i += 7;
					}
					else if(string[i+7] == 'a'){
						i += 5;
					}
					else{
						result = 0;
						break;
					}
				}
				else{
					result = 0;
					break;
				}
			}
			else{
				result = 0;
				break;
			}
		}
		else if(string[i+0] == 'e'){
			if(string[i+1] == 'r' && string[i+2] == 'a' && string[i+3] == 's' && string[i+4] == 'e'){
				if(string[i+5] == 'd' || string[i+5] == 'e' || string[i+5] == '\0'){
					i += 5;
				}
				else if(string[i+5] == 'r'){
					if(string[i+6] == '\0' || string[i+6] == 'e' || string[i+6] == 'd'){
						i += 6;
					}				
				}
				else{
					result = 0;
					break;
				}
			}
			else{
				result = 0;
				break;
			}
		}
		else{
			result = 0;
			break;
		}
	}
	if(result == 1){
		printf("YES");
	}
	else{
		printf("NO");
	}

	return 0;
}
