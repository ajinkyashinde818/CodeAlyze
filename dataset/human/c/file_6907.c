#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 1

int checkTrue(int* firstValue, int* secondValue)
{
	if (*firstValue == *secondValue)
	{
		printf("Yes \n");
	}
	else
	{
		printf("No \n");
	}
	return 0;
}

int main()
{
	int inputA[ARRAY_SIZE];
	int inputB[ARRAY_SIZE];
	int valueN, valueM;

	scanf("%d""%d", &inputA, &inputB);

	valueM = inputA[0];
	valueN = inputB[0];
	
	checkTrue(&valueM, &valueN);

	return 0;
}
