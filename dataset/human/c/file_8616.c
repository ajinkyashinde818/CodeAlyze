#include<stdio.h>
int main()
{
	int const MAXV=100000;
	int input=0;
	do{scanf("%d",&input);}while(input<2||input>100000);
	int buttons[MAXV]={0};
	int times=1;int num=0;
	for(int i=0;i<input;i++)
	{
		do{scanf("%d",&num);}while(num<1||num>input);
		buttons[i]=num;
	}
	int i=buttons[0];
	while(times<input)
	{
		if(i==2)
			break;
		i=buttons[i-1];
		times++;
	}
	if(times<input)
		printf("%d",times);
	else
		printf("-1");
	return 0;
}
