import sys
input = sys.stdin.readline
n,m = map(int, input().split())
ab = []
for _ in range(m):
    a,b = map(int, input().split())
    if a==1:
        ab.append(b)
    elif b==n:
        ab.append(a)
print('POSSIBLE' if len(ab)-len(set(ab)) != 0 else 'IMPOSSIBLE')
