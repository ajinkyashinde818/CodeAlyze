import numpy as np
N = int(input())
A = list(map(int,input().split()))

if sum((np.sign(A) ==-1)*1)%2 == 0:
    print(sum(abs(np.array(A))))
else:
    print(sum(abs(np.array(A)))-min(abs(np.array(A)))*2)
