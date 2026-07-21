from itertools import accumulate
N = int(input())
a = list(map(int, input().split()))

acc = list(accumulate(a))

ans = 10**18
for i in range(N-1):
    ans = min(ans, abs((acc[i])-(acc[-1]-acc[i])))
print(ans)
