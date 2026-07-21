import numpy as np
N,M = list(map(int,input().split()))

A=[]
B=[]
for n in range(N):
    A_ = list(input())
    A.append(A_)
    
for m in range(M):
    B_ = list(input())
    B.append(B_)
    
B=np.array(B)

ans='No'
for n1 in range(N-M+1):
    for n2 in range(N-M+1):
        check = np.array(A)[n1:n1+M,n2:n2+M]
        c=np.unique(check == B)
        
        if False not in set(c):
            ans='Yes'
            break
            
print(ans)
