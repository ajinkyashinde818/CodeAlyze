import sys

input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))
m = 0
zero = 0
ans = 0
odd = 10**9
for i in A:
    if i < 0:
        m += 1
    if i == 0:
        zero = 1
    ans += abs(i)
    if odd > abs(i):
        odd = abs(i)
if m %2 == 0 or zero:
    print(ans)
else:
    print(ans-odd*2)
