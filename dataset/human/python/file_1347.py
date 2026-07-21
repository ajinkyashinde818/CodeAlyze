from itertools import accumulate
N = int(input())
an = list(map(int, input().split()))
res = [0] + an
res = list(accumulate(res))
ans = 10e+9
for i in range(1, N):
    ans = min(ans, abs(res[i] - (res[-1]-res[i])))
print(ans)
