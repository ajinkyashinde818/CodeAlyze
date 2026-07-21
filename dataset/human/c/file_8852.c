#include <stdio.h>

int main(void){
	int H,W;
	char *p[51];
	char s[51][51];
	int i,j;
	
	scanf("%d",&H);
	scanf("%d",&W);
	
	for(i=0;i<H;i++){	//各行の開始アドレスの代入
		p[i]=s[i];
	}	
	for(i=0;i<H;i++){	//ポインタ配列を使った文字列の入力
		scanf("%s",p[i]);
	}
	
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(s[i][j]=='#'){
				if(s[i][j+1]=='#' || s[i+1][j]=='#' ||s[i][j-1]=='#'||s[i-1][j]=='#'){
					//ok
				}else{
					printf("No");
					goto result;
				}
			}
		}
	}
	printf("Yes");
	
	result:
	
	return 0;}
