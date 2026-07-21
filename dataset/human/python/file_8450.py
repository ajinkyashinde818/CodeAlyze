import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

k, n, *lst = map(int, read().split())
lst.sort()
dis = k
for i in range(n):
    if i == 0:
        tmp=lst[-1] - lst[0]
    else:
        tmp=k - lst[i] + lst[i - 1]
    dis=min(dis, tmp)
print(dis)
