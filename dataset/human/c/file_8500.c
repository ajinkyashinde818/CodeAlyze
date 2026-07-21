#include<stdio.h>

#define OFFSET 15

int matrix[10 + OFFSET][5];
int numberOfNull[5];

int Execute(int);

int main()
{
	int N;
	int i, j;
	int score, tmpScore;
	
	while(1)
	{
		score = 0;
		
		scanf("%d", &N);
		
		if(N == 0) break;
		
		for(i = OFFSET; i < OFFSET + N; i++)
		{
			for(j = 0; j < 5; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		
		do
		{
			tmpScore = Execute(N);
			score += tmpScore;
		} while(tmpScore > 0);
		
		printf("%d\n", score);
	}
	
	return 0;
}

int Execute(int n)
{
	int i, j, k, l, count, tmp;
	int result = 0;
	
	for(i = 0; i < 5; i++)
	{
		numberOfNull[i] = 0;
	}
	
	for(i = OFFSET + n - 1; i > OFFSET - 1; i--)
	{
		for(j = 0; j < 5; j++)
		{
			tmp = numberOfNull[j];
			while(matrix[i - numberOfNull[j]][j] == 0 && (i - numberOfNull[j]) > OFFSET - 1)
			{
				numberOfNull[j]++;
			}
		}
		
		for(k = 0; k < 3; k++)
		{
			count = 1;
			j = k;
			while(k < 4 && matrix[i - numberOfNull[k]][k] > 0 && matrix[i - numberOfNull[k]][k] == matrix[i - numberOfNull[k + 1]][k + 1])
			{
				count++;
				k++;
			}
			if(count > 2)
			{
				result += matrix[i - numberOfNull[k]][k] * count;
				l = j;
				while(l < j + count)
				{
					matrix[i - numberOfNull[l]][l] = 0;
					l++;
				}
			}
		}
	}
	
	return result;
}
