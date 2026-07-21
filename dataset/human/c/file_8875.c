#include <stdio.h>

#define	MAX_HW	50


int main(void)
{
	int h, w;
	char s[MAX_HW][MAX_HW+1];
	int i, j;
	
	scanf("%d %d", &h, &w);
	for(i=0; i<h; i++)
		scanf("%s", s[i]);
	
	for(i=0; i<h; i++)
		for(j=0; j<w; j++){
			if(s[i][j] == '.')
				continue;
			else if( s[i-1][j] == '#' && (i-1)>=0 )
				continue;
			else if( s[i][j+1] == '#' && (j+1)<w )
				continue;
			else if( s[i+1][j] == '#' && (i+1)<h )
				continue;
			else if( s[i][j-1] == '#' && (j-1)>=0 )
				continue;
			
			printf("No");
			return 0;
		}
	
	printf("Yes");
	
	
	return 0;
}
