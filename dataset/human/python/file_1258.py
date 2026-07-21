from itertools import accumulate

N = int(input())
a = list(map(int, input().split()))

s = list(accumulate(a))

ans = abs(2 * s[0] - s[-1])
for i in range(N-1):
    ans = min(ans, abs(2 * s[i] - s[-1]) )
    
print(ans)
