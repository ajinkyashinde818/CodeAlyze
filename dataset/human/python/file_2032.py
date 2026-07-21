n = int(input())
st = input()
di = {}
for i in range(len(st)):
    if st[i] in di:
        di[st[i]] = di.get(st[i]) + 1
    else:
        di[st[i]] = 2
from functools import reduce
print((reduce(lambda x,y:x*y,di.values())-1)%1000000007)
