#include <stdio.h>
int K,S;

int main()
{
    int x=0,y=0,z=0,sum=0;
    scanf("%d %d",&K,&S);

    for(x=0;x<=K;x++){
	for(y=0;y<=K;y++){
	    if(S-x-y<=K && S-x-y>=0)
		    sum++;
	}
    }

    printf("%d\n",sum);
    return 0;
}
