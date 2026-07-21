#include<stdio.h>
int main(void){
	int i[100000],x,y,z,a;
	
	x=0;
	z=0;
	
	while(1){
		scanf("%d",&i[x]);
		if(i[x]==0)
		{break;}
		x++;
		z++;
	}
	x=0;
	a=1;
	
	for(y=0;y<z;y++)
	{
	printf("Case %d: %d\n",a,i[x]);
	x++;
	a++;
	}
	return 0;
}
