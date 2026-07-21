#include <stdio.h>
#include <stdlib.h>

int getNumberOfLine();
int* CreatArrayThroughNumbersOfElements(int numbersOfElements);
int MaximumProfitFromArray(int* array, int number);

int main(void)
{
	int numbersOfLine = getNumberOfLine();
	int* moneyArray = CreatArrayThroughNumbersOfElements(numbersOfLine);
	int max = MaximumProfitFromArray(moneyArray, numbersOfLine);
	printf("%d\n", max);
}

int getNumberOfLine()
{
	int input;
	scanf("%d", &input);
	return input;
}

int* CreatArrayThroughNumbersOfElements(int numbersOfElements)
{
	int *p = (int*) malloc(numbersOfElements * sizeof(int));
	int i;
	for (i = 0; i < numbersOfElements; i++)
		scanf("%d", p + i);
	return p;
}

int MaximumProfitFromArray(int* array, int number)
{
	int i;
	int front, late;
	int minInSearchedElemets = *(array + 0);
	int subOfMaxInNotSearchedElements = 1, maxInNotSearchedElements = *(array + 1);
	int maxProfit = *(array + 1) - *(array);
	for (i = 1; i < number; i++)
	{
		if (*(array + i) > *(array + subOfMaxInNotSearchedElements))
		{
			subOfMaxInNotSearchedElements = i;
		}
	}
	maxInNotSearchedElements = *(array + subOfMaxInNotSearchedElements);
	// printf("In 47 lines, maxProfit = %d ", maxProfit);
	// printf("subOfMaxInNotSearchedElements = %d ", subOfMaxInNotSearchedElements);
	// printf("maxInNotSearchedElements = %d\n", maxInNotSearchedElements);
	// printf("minInSearchedElemets = %d\n", minInSearchedElemets);
	// printf("maxProfit = %d\n", maxProfit);


	for (front = 0; front < number - 1; front++)
	{
		if (*(array + front) > minInSearchedElemets)
		{
			// printf("front = %d, first if continue; now minInSearchedElemets = %d\n", front, minInSearchedElemets);
			continue;
		}
		minInSearchedElemets = *(array + front);
		// printf("change min to: %d\n", minInSearchedElemets);
		if (subOfMaxInNotSearchedElements > front)
		{
			if (maxProfit < maxInNotSearchedElements - *(array + front))
				maxProfit = maxInNotSearchedElements - *(array + front);
			continue;
		}
		subOfMaxInNotSearchedElements = front + 1;
		for (i = front + 1; i < number; i++)
		{
			// printf("now minInSearchedElemets = %d, and i = %d\n", minInSearchedElemets, i);
			if (*(array + i) > *(array + subOfMaxInNotSearchedElements))
			{
				subOfMaxInNotSearchedElements = i;
			}
		}
		maxInNotSearchedElements = *(array + subOfMaxInNotSearchedElements);
		// printf("now min = %d, maxInNotSearchedElements = %d\n", minInSearchedElemets, maxInNotSearchedElements);
		if (maxProfit < maxInNotSearchedElements - *(array + front))
		{
			// printf("front = %d, when min = %d\n", front, minInSearchedElemets);
			maxProfit = maxInNotSearchedElements - *(array + front);
		}

	}

	return maxProfit;
}
