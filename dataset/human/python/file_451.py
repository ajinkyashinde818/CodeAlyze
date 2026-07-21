import numpy as np
N = int(input())
A = np.array(list(map(int,input().split())))
abs_A = [abs(i) for i in A]
ans = 0
if (0 in A) or (np.count_nonzero(A<0) % 2 == 0):
    ans = sum(abs_A)
else:
    ans = sum(abs_A) - 2*min(abs_A)
print(ans)
