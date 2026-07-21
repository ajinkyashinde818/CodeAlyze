#include <stdio.h>
int main(){
	int h,w,i,j,detect;
	scanf("%d%d",&h,&w);
	char cam[51][51];
	for(i=0;i<h;i++){
		scanf("%s",cam[i]);
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(cam[i][j] == '#'){
				detect = 1;
				if(i>0 && cam[i-1][j] == '#') detect = 0;
				if(i<h-1 && cam[i+1][j] == '#') detect = 0;
				if(j>0 && cam[i][j-1] == '#') detect = 0;
				if(j<w-1 && cam[i][j+1] == '#') detect = 0;
				if(detect == 1) break;
			}
		}
		if(detect == 1) break;
	}
	if(detect == 1) printf("No\n");
	else printf("Yes\n");
}
