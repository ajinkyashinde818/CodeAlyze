import sys
import numpy as np

read = sys.stdin.read

def dubbling(a:np.array, k:int, MAXk=10**12) -> np.array:
    bl = MAXk.bit_length()
    b = np.empty([bl,len(a)+1], dtype=np.int64)
    b[0] = np.append(a, -1)
    for i in range(1,bl):
        x = b[i-1]
        b[i] = x[x]
    X1 = b[np.array(list(format(k,'0'+str(bl)+'b')), dtype=np.int8).astype(np.bool)[::-1]]
    ret = np.append(np.arange(len(a)), -1)
    for i in X1:
        ret = ret[i]
    return ret

n, k = map(int, input().split())
a = np.array(read().split(), dtype=np.int64)
maxk = 10**18

ans = dubbling(a-1, k, MAXk=maxk)[0] + 1
print(ans)
