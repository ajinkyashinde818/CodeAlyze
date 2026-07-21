import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
x = list(map(int, input().split()))
M = 10**9+7
p = 1
invs = [None]
v = 1
for i in range(2, n+1):
    invs.append(v)
    v += pow(i, M-2, M)
    v %= M
for i in range(1, n):
    p *= i
    p %= M
ans = 0
for i in range(n-1):
    ans += (x[i+1]-x[i]) * invs[i+1]
    ans %= M
ans *= p
print(ans%M)
