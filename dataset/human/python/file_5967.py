import sys
input = sys.stdin.readline

n = int(input())
*a, = map(int, input().split())
*b, = map(int, input().split())
*c, = map(int, input().split())

ans = 0
for i in range(len(a)-1):
    ans += b[a[i]-1]
    if a[i]+1 == a[i+1]:
        ans += c[a[i]-1]
ans += b[a[-1]-1]
print(ans)
