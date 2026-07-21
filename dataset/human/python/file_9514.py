from sys import stdin
import numpy as np
 
def main():
    N, K = [int(x) for x in stdin.readline().rstrip().split()]
    A = [int(x) for x in stdin.readline().rstrip().split()]
    X = 1
    L = [1]
    if A[0] == 1:
        print(1)
        exit()
    if N >= K :
        for i in range(K):
            X = A[X-1]
        print(X)
        exit()
    else:
        for i in range(N):
            X = A[X-1]
            L += [X]
        #print('L',L)#OK
        C = np.zeros(N)
        for i in range(N):
            if C[L[i]-1] == 0:
                C[L[i]-1] += 1
                #print('C,i',C,i)
            else:
                break
        #print('C',C)
        #print('i+1',i+1)#Roop 回数　When Roop Goal
        #print('L[i+1]',L[i+1])#Roop initial Number
        S = L.index(L[i+1])
        #print('S',S)#When Roop Start ,Roop times
        #print(K - i-1)#Remain K
        #print('i + 1 -S',i + 1 - S)#Roop Cycle
        K = (K - i-1)%(i+1 - S)
        #print(K)
        print(L[S+K])
        
main()
