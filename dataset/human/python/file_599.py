import numpy as np

n = int(input()) 

nums = list(map(int, input().split()))

minus = 0
zero = 0
for num in nums:
    if num == 0:
        zero += 1
        break
    elif num < 0:
        minus += 1

nums = np.abs(nums)
nums.sort()

if minus % 2 and not zero:
    ans = sum(nums) - 2 * nums[0]

else:
    ans = sum(nums)

print(ans)
