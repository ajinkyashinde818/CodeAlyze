import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))


minn = 10**10
cnt = 0
ans = 0
for i in range(n):
    temp = abs(a[i])
    minn = min(temp, minn)

    ans += temp

    if a[i]<0:
        cnt += 1



if cnt % 2 == 0:
    print(ans)
else:
    print(ans - 2*minn)
