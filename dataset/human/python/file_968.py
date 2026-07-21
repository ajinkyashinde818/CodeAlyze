import sys
input = sys.stdin.readline

N = int(input())
S = input().rstrip()
mod = 10**9 + 7
cnt = 0
ans = 1
for c in S:
    if (c == 'W') ^ (cnt % 2 == 1):
        ans = ans * cnt % mod
        cnt -= 1
    else:
        cnt += 1
if cnt > 0:
    ans = 0
for i in range(1, N+1):
    ans = ans * i % mod
print(ans)
