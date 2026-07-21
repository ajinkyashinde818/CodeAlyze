#include <stdio.h>
#include <limits.h>

int nums[2000005];

int main() {
#ifdef TEST
    freopen("input", "r", stdin);
#endif

    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &nums[i]);
    }

    int minn = nums[0];
    int maxProfit = INT_MIN;
    for (int j = 1; j < num; ++j) {
        int tmp = nums[j];
        nums[j] -= minn;
        minn = minn < tmp ? minn : tmp;
        if (nums[j] > maxProfit) {
            maxProfit = nums[j];
        }
    }
    printf("%d\n", maxProfit);


    return 0;
}
