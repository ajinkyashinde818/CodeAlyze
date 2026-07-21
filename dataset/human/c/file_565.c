#include <stdio.h>

int main(){
	int n, m; //文字列の大きさ
	int i,j;
	int k,l;
	int x;
	scanf("%d %d", &n, &m);
	char A[n+1][n+1];
	char B[m+1][m+1];

	for(j = 0; j < n; j++){
		scanf("%s", A[j]);
	}
	
	for(j = 0; j < m; j++){
		scanf("%s", B[j]);
	}

	for(i = 0; i <= n-m; i++){
		for(j = 0; j <= n-m; j++){
			//どっかしらがfitした
			if(A[j][i] == B[0][0]){
				x = 1;
				for(k = 0; k < m; k++){
					for(l = 0; l < m; l++){
						if(A[j+l][i+k] != B[k][l]){
							x = 0;
							break;	//一致しなかったら強制退出
						}
					}
					//途中でおわったやつ　or ぜんぶループしたやつもここ出てくる
					if(x == 0) break;	//途中でbreakしたやつは用なしだからbreak
				}
				if(x == 1){
					printf("Yes\n");
					return 0;
				}
			}
			//全箇所fitしなかったやつがでてくる，B[1][1]を調べるループ開始
		}
	}

	printf("No\n");

	return 0;
}
