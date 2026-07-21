from itertools import accumulate
n = int(input())
li = [int(x) for x in input().split()]
X = list(accumulate(li))

ans = float("inf")
for i in range(n-1):
    ans =min(ans ,abs(X[-1] - X[i]*2))
print(ans)
