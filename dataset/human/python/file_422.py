import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
a = []
f = True
A = map(int, input().split())

for i in A:
    if i < 0:
        f ^= 1
    a.append(abs(i))

a.sort()

ans = sum(a[1:])

print(ans + (a[0] if f else -a[0]))
