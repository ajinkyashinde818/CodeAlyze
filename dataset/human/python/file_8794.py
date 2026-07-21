import numpy as np
def resolve():
    K,N = map(int,input().split())
    A = np.array(list(map(int,input().split())))
    Adiff = np.diff(A)
    max_gap = max(max(Adiff), A[0] + K - A[N-1])
    print(K-max_gap)
resolve()
