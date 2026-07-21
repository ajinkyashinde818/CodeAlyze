import numpy as np

k,n = map(int,input().split())
a_ls = list(map(int,input().split()))

next_ls = [0] * n
for i in range(n-1):
    next_ls[i] = a_ls[i+1] - a_ls[i]
next_ls[n-1] = k - a_ls[-1] + a_ls[0]
argmax = np.argmax(next_ls)
next_ls.pop(argmax)
print(sum(next_ls))
