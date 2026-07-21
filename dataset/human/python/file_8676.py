from sys import stdin
input = stdin.readline

k, n = list(map(int, input().split()))
a = list(map(int, input().split()))
d = [a[i+1]-a[i] for i in range(n-1)]
d.append(a[0]+k-a[-1])
print(k-max(d))
