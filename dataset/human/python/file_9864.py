N, K = list(map(int, input().split(" ")))
A = list(map(int, input().split(" ")))
 
import numpy as np
 
 
 
Nstock = np.zeros(N)
 
cpos = 1
Nstock[cpos - 1] = 1
stock = [cpos]
loop = []
 
idx = 0
for i in range(K):
    cpos = A[cpos-1]
    if Nstock[cpos - 1]  == 1:
        idx = stock.index(cpos)
        loop = stock[idx:]
        break
    Nstock[cpos - 1] = 1
    stock.append(cpos)
    
if loop != []:
    v = (K - idx) 
    a = v %len(loop)
    print(loop[a])
else:
    print(stock[K])
