#include <stdio.h>

int	main(void)
{
	int join_times = 0;
	int disp_rare = 0;
	int inter_rate = 0;
	
	scanf("%d %d", &join_times, &disp_rare);

	if(join_times >= 10)
	{
		printf("%d\n", disp_rare);
	}
	else
	{
		inter_rate = disp_rare + (100 * (10 - join_times));
		printf("%d\n", inter_rate);
	}
	return (0);
}
