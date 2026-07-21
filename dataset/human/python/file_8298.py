import numpy as np
def main():
    N = int(input())
    A = np.array(list(map(int,input().split())))
    S = np.sum(A)
    s = N*(N+1)//2
    if S%s : print("NO");return
    k = S//s
    B = A - np.arange(1,N+1)*k
    D = B[1:]-B[:-1]
    if (np.all(D<=0)) and (np.all(D%N==0)):
        print("YES")
    else:
        print("NO")
    
main()
