from sys import stdin
n = int(input())
a = list(map(int, stdin.readline().split()))
b = list(map(int, stdin.readline().split()))
c = list(map(int, stdin.readline().split()))
ans = sum(b)
for i in range (n-1):
    if a[i]+1 == a[i+1]:
        t = a[i]-1
        ans +=c[t]
print(ans)
