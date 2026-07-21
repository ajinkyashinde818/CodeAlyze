import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
count = 0
for i in range(n):
  count += b[i]
for j in range(n-1):
  if a[j] + 1 == a[j+1]:
    count += c[a[j]-1]
print(count)
