import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

k, n, *a = map(int, read().split())
a = sorted(a)
d = [a[0]+k-a[-1]]
for i in range(n-1):
    d.append(a[i+1]-a[i])
print(sum(d)-max(d))
