#include<stdio.h>
#include<stdlib.h>

const int MOD_VALUE = 1000000007;


int main(void){

	int h,w,k;

	int in[300][300];
	int out[300][300];

	int bot[300];
	int top[300];
	int non[300];

	int i,j;
	char buff;
	int l_flag;
	int n_line;

	int index;

	scanf("%d %d %d",&h,&w,&k);

	index = 1;

	for(i=0;i<h;i++){
		for(j=0;j<w;j++){

			//初期化
			out[i][j] = -1;

			scanf("%c",&buff);

			if(buff == '\n'){
				scanf("%c",&buff);
			}

			if(buff == '#'){
				in[i][j] = 1;
			}else{
				in[i][j] = 0;
			}
		}
	}

	// a,b[h][w]
	for(i=0;i<w;i++){
		bot[i] = -1;
		top[i] = -1;
		for(j=0;j<h;j++){
			if(in[j][i] == 1){

				// botの更新
				if(bot[i] == -1){ bot[i] = j; }

				// topの更新
				top[i] = j;
			}
		}
	}

	n_line = -1;
	for(i=0;i<w;i++){
		non[i] = -1;
		if(bot[i] != -1){
			if(n_line == -1){n_line = i;}
			non[i] = 1;
		}
	}
/*
	printf("\n===in===\n");
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			printf("%d ",in[i][j]);
		}
		printf("\n");
	}


	printf("\n===top===\n");
	for(i=0;i<w;i++){
		printf("%d ",top[i]);
	}

	printf("\n===bot===\n");
	for(i=0;i<w;i++){
		printf("%d ",bot[i]);
	}

	printf("\n===non===\n");
	for(i=0;i<w;i++){
		printf("%d ",non[i]);
	}

	printf("\nn_line : %d\n",n_line);
	*/

	for(i=n_line;i<w;i++){
		if(non[i] == 1){
			for(j=0;j<h;j++){
				if(in[j][i] == 1){
					if(j != bot[i]){
						index++;
					}
				}
				out[j][i] = index;
			}
			index++;
		}else{
			for(j=0;j<h;j++){
				out[j][i] = out[j][i-1];
			}
		}
	
	}
	for(i=n_line-1;i>=0;i--){
		for(j=0;j<h;j++){
			out[j][i] = out[j][i+1];
		}
	}

//	printf("\n===out===\n");
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			printf("%d ",out[i][j]);
		}
		printf("\n");
	}


	return 0;
}
