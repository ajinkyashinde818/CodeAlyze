import sys
input = sys.stdin.readline
N = int(input())
a = [int(x) for x in input().split()]
x = a[0]
y = sum(a[1:])
ans = [abs(x - y)]
for i in range(1,N-1):
    x += a[i]
    y -= a[i]
    ans.append(abs(x - y))
print(min(ans))
