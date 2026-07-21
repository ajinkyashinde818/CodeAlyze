n = int(input())
li = list(map(int,input().split()))

from itertools import accumulate

lin = list(accumulate(li))
mi = 10**18
S = sum(li)

for i in range(n-1):
    ara = lin[i]
    sunu = S-ara
    mi = min(mi,abs(ara-sunu))

print(mi)
