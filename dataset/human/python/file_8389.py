import sys
input = sys.stdin.readline
'''
n, m = map(int, input().split())
n = int(input())
A = list(map(int, input().split()))
for test in range(int(input())):
'''
inf = 100000000000000000  # 1e17

n, m = map(int, input().split())
A = list(map(int, input().split()))
A.append(n + A[0])
ans=0
for i in range(m):
    ans = max(ans, A[i + 1] - A[i])
print(n - ans)
