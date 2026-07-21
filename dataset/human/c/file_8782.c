#include <stdio.h>
int main(void)
{
	int h,w,i,j,a=0;
	char s[51][51];
	scanf("%d%d",&h,&w);
	for(i=0; i<h; i++){
		scanf("%s",&s[i]);
	}
	for(i=0; i<h; i++){
		for(j=0; j<w; j++){
			if(s[i][j]=='#'){
				if(s[i+1][j]!='#' && s[i-1][j]!='#' && s[i][j+1]!='#' && s[i][j-1]!='#'){
					a=1; break;
				}
			}
		}
	}
	
	if(a==1)	printf("No\n");
	if(a==0)	printf("Yes\n");
	return 0;
}
