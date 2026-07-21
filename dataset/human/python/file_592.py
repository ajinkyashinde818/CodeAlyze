import numpy as np

N = int(input())
As=input().split()
A = np.array([int(s) for s in As])
del(As)
Ans = np.sum(np.abs(A))
co = np.sum(A < 0)
if co%2==0:
    print(Ans)
else:
    Ans = Ans - 2*np.amin(np.abs(A))
    print(Ans)
