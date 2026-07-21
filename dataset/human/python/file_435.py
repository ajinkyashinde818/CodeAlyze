import numpy as np

n = int(input())
a = list(map(int, input().split()))
na = np.array(a)
total = 0

wh = len([i for i in a if i <= 0])

if wh % 2 == 0 :
    print(sum(np.abs(na)))
else :
    m = min(np.abs(na))
    print(sum(np.abs(na)) - 2*m)
