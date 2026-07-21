import numpy as np
def resolve():
    N,K = map(int,input().split())
    A = list(input().split())
    current_p = 0
    loop_length = 0
    loop_start = 0
    Nlist = - np.ones(N, dtype = int)
    Nlist[0] = 0
    for i in range(1, min(N + 1,K + 1)):
        next_p = int(A[current_p]) - 1
        if Nlist[next_p] == -1:
            current_p = next_p
            Nlist[next_p] = i
        else:
            loop_start = Nlist[next_p]
            loop_length = i - loop_start
            break
    if loop_length != 0:
        ans =  loop_start + (K - loop_start) % loop_length
    else:
        ans = K 
    print(np.where(Nlist == ans)[0][0] + 1)
resolve()
