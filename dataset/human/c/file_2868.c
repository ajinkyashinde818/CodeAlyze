#include <stdio.h>

int main(void)
{
	int k, s;
	int x, y, z;
	int count = 0;
	
	scanf("%d %d", &k, &s);
	
	for(x=0; x<=k; x++){
		if( (x+2*k) < s )
			continue;
		else if(x > s)
			break;
		
		for(y=0; y<=k; y++){
			if( (x+y+k) < s )
				continue;
			else if( (x+y) > s )
				break;
			else if( s-(x+y) >= 0 )
				count++;
			//for(z=0; z<=k; z++)
		}
	}
	
	printf("%d\n", count);
	
	
	return 0;
}
