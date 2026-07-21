#include<stdio.h>
int main(void){
	int n;
	int i,j,k;
	int count = 0;
	int tmp[100];
	int station[52];
	int num[100];
	char str[256];
	for(i = 0;i < 26;i++){
		station[i] = i + 97;
	}
	for(i = 26;i < 52;i++){
		station[i] = i + 39;
	}
	while(scanf("%d",&n)){
		if(n == 0){
			break;
		}
		for(i = 0;i < n;i++){
			scanf("%d",&num[i]);
		}
		scanf("%s",str);
		i = 0;
		k = 0;
		while(str[i] != '\0'){
			for(j = 0;j < 52;j++){
				if(str[i] == station[j]){
					tmp[i] = j - num[k];
					if(tmp[i] < 0){
						tmp[i] += 52;
					}
				}
			}
			i++;
			k++;
			count++;
			if(k == n){
				k = 0;
			}
		}
		for(i = 0;i < count;i++){
			printf("%c",station[tmp[i]]);
		}
		printf("\n");
		count = 0;
	}
	return 0;
}
