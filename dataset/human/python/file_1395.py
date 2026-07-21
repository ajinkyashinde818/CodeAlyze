from itertools import accumulate
n = int(input())
cards = list(map(int, input().split()))
sums = list(accumulate(cards))
ans = float("inf")
for i in range(n-1):
    ans = min(ans, abs(sums[-1] - 2 * sums[i]))
print(ans)
