#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int au[50][50], bi[50][50];
	char ai[50];
	for(int i=0; i<n; i++){
		scanf("%s", ai);
		for(int j=0; j<n; j++){
			if(ai[j] == '.') au[i][j] = -1;
			else if(ai[j] == '#') au[i][j] = 1;
			else au[i][j] = 0;
		}
	}
	for(int i=0; i<m; i++){
		scanf("%s", ai);
		for(int j=0; j<m; j++){
			if(ai[j] == '.') bi[i][j] = -1;
			else bi[i][j] = 1;
		}
	}

	/*
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", au[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			printf("%d ", bi[i][j]);
		}
		printf("\n");
	}
	*/

	int judge = m*m, answer=0;;
	for(int i=0; i<=n-m; i++){
		for(int j=0; j<=n-m; j++){
			if(bi[0][0] == au[i][j]){
				int count = 0;
				for(int k=0; k<m; k++){
					for(int l=0; l<m; l++){
						if(bi[k][l] == au[i+k][j+l]) count++;
					}
				}
				if(count == judge) answer = 1;
			}
		}
	}

	if(answer == 1) printf("Yes\n");
	else printf("No\n");

	return 0;
}
