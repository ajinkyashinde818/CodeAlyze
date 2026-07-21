#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int H,W;
	scanf("%d%d", &H,&W);
	char s[50][50];
	for (int i=0;i<W;i++) {
	    scanf("%s", &s[i]);
	}
	int end=1;
	int check =1;
	for (int i=1;i<=H;i++) {
		for(int j=1;j<=W;j++) {
			if (s[i][j]=='#') {
				if (s[i-1][j] == '#'||s[i+1][j] == '#'||s[i][j-1] == '#'||s[i][j+1] == '#') check=1;
				else { 
				    check=0;
					break;
			    }
			}
		}
		if (check==0) { 
		    int end=0; break;
		}
	}
	if (check ==0) puts("No");
	else puts("Yes");
	return(0);
}
