import numpy as np
N = int(input())
A = np.array([int(i) for i in input().split()])
negative_count = np.sum(A<0)

abs_A = list(map(abs, A))
if(negative_count%2==0):
    print(int(np.sum(abs_A)))
else:
    print(int(np.sum(abs_A) - (min(abs_A)*2)))
