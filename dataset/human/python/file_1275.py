import sys
input = sys.stdin.readline

N = int(input())
a = list(map(int, input().split()))
acc = [0]

for ai in a:
    acc.append(acc[-1]+ai)

ans = 10**18

for i in range(1, N):
    ans = min(ans, abs(acc[i]-(acc[N]-acc[i])))

print(ans)
