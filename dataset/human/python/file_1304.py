from itertools import accumulate

N = int(input())
a = list(map(int, input().split())) 

b = list(accumulate(a))
ma = b[-1]
mi = 10**10
for sunuke in b[:N-1]:
    arai = ma - sunuke
    if abs(sunuke - arai) < mi:
        mi = abs(sunuke - arai)
print(mi)
