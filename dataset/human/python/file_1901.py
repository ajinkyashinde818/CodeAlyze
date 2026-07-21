import numpy as np

N,M = map(int, input().split())

A=[]
for i in range(N):
    A.append(list(input()))

B=[]
for j in range(M):
    B.append(list(input()))

A=np.asarray(A)
B=np.asarray(B)
flg=False

  
for x in range(N-M):
    for y in range(N-M):
        if (A[x:x+M,y:y+M] == B).all():
            flg=True
if flg:
    print("Yes")
else:
    try:
        if (A == B).all():
            print("Yes")
        else:
            print("No")
    except:
        print("No")
