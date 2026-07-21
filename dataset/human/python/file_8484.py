import sys
def input(): return sys.stdin.readline().rstrip()
sys.setrecursionlimit(10 ** 7)

K, N = map(int, input().split())
A = list(map(int, (input().split())))
A.append(K+A[0])

ans = K
for i in range(N):
    ans = min(ans, K-(A[i+1]-A[i]))

print(ans)
