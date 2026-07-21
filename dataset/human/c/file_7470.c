#include<stdio.h>

int main(void) {
        int nums[10000];
        int i, count = 1;

        while(1) {
                scanf("%d",&nums[count]);
                if(nums[count] == 0) break;
                count++;
        }

        for(i = 1; i < count; i++) {
                printf("Case %d: %d\n", i, nums[i]);
        }

        return 0;
}
