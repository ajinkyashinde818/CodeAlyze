from sys import stdin

n = int(stdin.readline().rstrip())

an = list(map(int, input().split()))
bn = list(map(int, input().split()))
cn = list(map(int, input().split()))

ans = 0
for i in range(n):
    ans += bn[an[i]-1]
    if i != 0:
        if an[i-1]+1 == an[i]:
            ans += cn[an[i-1]-1]

print(ans)
