from sys import *

input = stdin.readline
lmi = lambda: list(map(int, input().split()))
mi = lambda: map(int, input().split())
si = lambda: input().strip('\n')
ssi = lambda: input().strip('\n').split()


n, r = mi()
if n >= 10:
    print(r)
else:
    print(r+(100*(10-n)))
