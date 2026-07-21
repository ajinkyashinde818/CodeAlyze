import numpy as np
N, K = list(map(int, input().split()))
A = np.array(list(map(int, input().split()))) - 1
mem = {}

c = 0 # 現在の場所
cK = 0 # 現在の回数
flg = True
mem[c] = 0
for k in range(1, K+1):
    c = A[c] # k回目の移動先
    if c in mem:
        T = k - mem[c]
        cK = k
        flg = False
        break
    mem[c] = k

if flg:
    print(c+1)
else:
    iterN = int(np.mod(int(K - cK), int(T)))
    for i in range(iterN):
        c = A[c]
    print(c+1)
