import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
cnt = b[a[0] - 1]
for i in range(1, n):
    cnt += b[a[i] - 1]
    if a[i] == a[i - 1] + 1:
        cnt += c[a[i - 1] - 1]
print(cnt)
