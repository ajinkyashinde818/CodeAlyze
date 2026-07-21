import numpy as np

N = int(input())
A = np.array(list(map(int,input().split())))

fu = np.sum(A < 0)

if fu == 0:
    print(np.sum(A))
elif fu%2 == 0:
    print(np.sum(abs(A)))
else:
    b = min(abs(A))
    print(np.sum(abs(A)) - 2*b)
