from itertools import accumulate

N = int(input())
a = list(map(int, input().split(' ')))
suma = list(accumulate(a))
ans = 10**18
for i in range(N-1):
    ans = min(ans, abs((suma[-1]-suma[i])-suma[i]))

print(ans)
