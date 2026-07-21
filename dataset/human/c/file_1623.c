#include <stdio.h>
#include <string.h>

int main(void) {
	static char message[1000][1064];
	int n;
	while(scanf("%d",&n)==1 && n>0) {
		int i,j;
		char plus_flag[1064]={0};
		memset(message,0,sizeof(message));
		for(i=0;i<n;i++)scanf("%s",message[i]);
		for(i=0;i<n;i++) {
			for(j=0;message[i][j]=='.';j++);
			if(j>0)message[i][j-1]='+';
		}
		for(i=n-1;i>=0;i--) {
			for(j=0;message[i][j]=='.' || message[i][j]=='+';j++) {
				if(message[i][j]=='.') {
					message[i][j]=(plus_flag[j]?'|':' ');
				} else {
					plus_flag[j]=1;
				}
			}
			for(;j<1064;j++)plus_flag[j]=0;
		}
		for(i=0;i<n;i++)puts(message[i]);
	}
	return 0;
}
