#include<stdio.h>
int sharp(int);
int dot(int);

int main(void){
	int H, W;	//縦x横
	int i, j;	//ループ用変数

	while (1){
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0) break;
		for (i = 0; i < H; i++){
			if (i % 2 == 0) sharp(W);
			if (i % 2 == 1) dot(W);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

int sharp(int n){		//#から初めて#と.を交互に表示する関数
	int i;	//ループ用変数
	for (i = 0; i < n; i++){
		if (i % 2 == 0) printf("#");
		if (i % 2 == 1) printf(".");
	}
	return 0;
}

int dot(int n){	//.から初めて.と#を交互に表示する関数
	int i;
	for (i = 0; i < n; i++){
		if (i % 2 == 0) printf(".");
		if (i % 2 == 1) printf("#");
	}
	return 0;
}
