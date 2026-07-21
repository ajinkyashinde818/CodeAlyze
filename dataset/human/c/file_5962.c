#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define DT_MAX (200000)

int data[DT_MAX];
int out_data[DT_MAX];
int out_data_num;


int main()
{
	int n,i;
	char buff[8192];
	int min;
	int wk,delta;

	out_data_num = 0;
	gets(buff);
	sscanf(buff,"%d",&n);

	for (i=0 ; i<n ; i++) {
		gets(buff);
		sscanf(buff,"%d",&(data[i]));

	}

	min = data[0];
	delta= data[1] - data[0];
	for (i=1 ; i<n ; i++) {
		wk = data[i-1];
		if (min > wk) {
			min = wk;
		}
		wk = data[i]-min;
		if (delta < wk) {
			delta = wk;
		}
	}
			
	printf("%d\n",delta);
	return 0;
}
