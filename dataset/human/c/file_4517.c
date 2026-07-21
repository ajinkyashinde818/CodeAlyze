#include<stdio.h>
#include<string.h>

#define YES "Yes"
#define NO "No"

int main()
{
    int n, answer = 0;
    int d_array[100][2];

    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d %d", &d_array[i][0], &d_array[i][1]);
    }

    for (int i = 0; i<n; i++)
    {
        if (d_array[i][0] == d_array[i][1])
        {
            answer ++;
        } else {
            answer = 0;
        }

        if (answer >= 3)
        {
            break;
        }
    }

    if (answer >= 3)
        printf("%s", YES);
    else
        printf("%s", NO);
    

    return 0;
}
