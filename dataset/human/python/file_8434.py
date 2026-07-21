from sys import stdin
k,n = [int(x) for x in stdin.readline().rstrip().split()]
a = [int(x) for x in stdin.readline().rstrip().split()]
b = [0] * n
for i in range(n-1):
    b[i] = a[i+1] - a[i]
b[n-1] = k - a[n-1] + a[0]
print(sum(b) - max(b))
