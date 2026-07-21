#include <stdio.h>
#include <ctype.h>

int sub(char str[]){
	int i, ret, mul[4] = {1000,100,10,1}, count;
	char unit[5] = {"mcxi"};
	count = ret = 0;
	for(i = 0;i < str[i] != '\0';i++){
		if(isdigit(str[i])){
			while(str[i + 1] != unit[count])
				count++;
			ret += (str[i++] - '0') * mul[count++];
		}
		else{
			while(str[i] != unit[count])
				count++;
			ret += mul[count++];
		}
	}
	return ret;
}


int main(void){
	int n, i, j, res , count;
	char str1[9], str2[9], c, unit[5] = {"mcxi"};
	scanf("%d%*c",&n);
	for(i = 0;i < n;i++){
		j = 0;
		while((c = getchar()) != ' ')
			str1[j++] = c;
		str1[j] = '\0';
		j = 0;
		while((c = getchar()) != '\n')
			str2[j++] = c;
		str2[j] = '\0';
		res = sub(str1) + sub(str2);
		count = 0;
		for(j = 1000;j > 0;j /= 10){
			if(res / j == 1){
				printf("%c",unit[count++]);
				res -= j;
			}
			else if(res / j){
				printf("%d%c",res / j,unit[count++]);
				res %= j;
			}
			else
				count++;
		}
		printf("\n");
	}
	return 0;
}
