import sys
input = sys.stdin.readline
N = int(input())
a = [int(i) for i in input().split()]
sum = 0
for i in range(N) :
    sum+=a[i]
ans = 2000000000
suma = 0
for i in range(N) :
    suma += a[i]
    d = abs(sum - 2 * suma)
    if i + 1 < N :
        ans = min(d,ans)
print(ans)
