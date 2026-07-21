from sys import stdin
from random import randint
from time import time
input = lambda: stdin.readline().rstrip()
start = time()
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
b.reverse()
good = False
t = time() - start
while t < 1.8:
    ok = True
    for i in range(n):
        if a[i] == b[i]:
            rng = randint(0, n - 1)
            b[i], b[rng] = b[rng], b[i]
            ok = False
    if ok:
        good = True
        break
    t = time() - start
if good:
    print("Yes")
    print(*b)
else:
    print("No")
