#include<stdio.h>
int main()
{
    int N,R,inner_rating,i;
    scanf("%d %d",&N,&R);
    if(N<10)
    {
    	i=100*(10-N);
    	inner_rating=i+R;
	}
	else 
	{
		inner_rating=R;
	}
	printf("%d\n",inner_rating);
	return 0;
}
