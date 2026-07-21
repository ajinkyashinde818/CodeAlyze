import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()

n = ni()
li = na()
ct = 0
s1 = 0
li2 = []
m = -1000000000000000000
for i in range(n):
    s1 += abs(li[i])
    li2.append(abs(li[i]))
    if li[i] < 0:
        ct += 1
if ct % 2 == 0:
    print(s1)
else:
    print(s1-2*min(li2))
