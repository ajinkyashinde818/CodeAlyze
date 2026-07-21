#include <stdio.h>

int main(int argc, char const *argv[])
{
    int testcase_total = 0;
    int testcase_right = 0;

    scanf("%d %d", &testcase_total, &testcase_right);

    if (testcase_total == testcase_right)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
