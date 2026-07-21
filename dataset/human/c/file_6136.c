#include <stdio.h>


int main()
{
	int n;
	int box[200000];
	int max, min, i, j;


	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &box[i]);

// 回答を見る前
/*
	max = box[1] - box[0];
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if((box[j] - box[i]) > max)
				max = box[j] - box[i];
		}
	}
*/
//	回答見た後
	max = box[1] - box[0];
	min = box[0];
	for(i = 1; i < n; i++){
		if(max < box[i] - min)
			max = box[i] - min;
		if(min > box[i])
			min = box[i];
	}

	printf("%d\n", max);

	return 0;
}
