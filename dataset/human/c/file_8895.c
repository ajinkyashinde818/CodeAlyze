#include <stdio.h>

int main()
{
	int h, w;
	int i, j;
	char p[52][53]={NULL};

	scanf("%d%d", &h, &w);

	for(i=0; i < h; i++){
		scanf("%s", &p[i+1][1]);
	}

	for(i=1; i <= h; i++){
		for(j=1; j <= w; j++){
			if(p[i][j] == '#' && p[i-1][j] != '#' && p[i+1][j] != '#' && p[i][j-1] != '#' && p[i][j+1] != '#'){
				break;
			}
		}
		if(j != w+1){break;}
	}


	if(i == h+1 && j == w+1){
		printf("Yes");
	}
	else{
		printf("No");
	}


return 0;
}
