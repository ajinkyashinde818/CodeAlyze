import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, k, *a = map(int, read().split())
dict = [-1] * (n + 1)
now = a[0]
dict[0] = 0
for i in range(1, n * 2):
    if i == k:
        print(now)
        exit()
    now = a[now - 1]
    if dict[now] != -1:
        k -= (i + 1)
        k %= (i - dict[now])
        break
    else:
        dict[now] = i
for i in range(k):
    now = a[now - 1]
print(now)
