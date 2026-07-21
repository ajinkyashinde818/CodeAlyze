#include <stdio.h>
#include <stdlib.h>

int cmp(const void *n1, const void *n2)
{
    return *(int *)n1 - *(int *)n2;
}

int main(void)
{

    int totalDistance, houseNum;
    
    scanf("%d%d", &totalDistance, &houseNum);

    int distance[houseNum];
    for (int index = 0; index < houseNum; index++)
    {
        scanf("%d", &distance[index]);
    }

    int moveDistance[houseNum * 2];
    for (int index = 0; index < houseNum * 2; index++)
    {
        if (index == 0)
        {
            moveDistance[index] = distance[houseNum - 1] - distance[index];
        }
        else if (index == (houseNum * 2) - 1)
        {
            moveDistance[index] = distance[houseNum - 1] - distance[0];
        }
        else if (index % 2 == 1)
        {
            moveDistance[index] = totalDistance - distance[index / 2] + distance[(index / 2) + 1];
        }
        else
        {
            moveDistance[index] = totalDistance - distance[index / 2] + distance[(index / 2) - 1];
        }
    }

    qsort(moveDistance, houseNum * 2, sizeof(int), cmp);

    printf("%d", moveDistance[0]);

}
