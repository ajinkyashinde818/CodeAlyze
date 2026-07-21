N,K=map(int, input().split())
A=list(map(int, input().split()))
import sys
sys.setrecursionlimit(10**8)
import numpy as np
done=np.array([0]*N)
X=[0]*2
L=[]
F=[True]
def dfs(start, steps):
    done[start-1]+=1
    L.append(start)
    if done[start-1]==3:
        X[1]=steps
        return
    elif done[start-1]==2 and F[0]:
        X[0]=steps
        F[0]=False
    nex=A[start-1]
    dfs(nex, steps+1)
dfs(1,0)
#print(done)
#print(X)
#print(L)
first=L[:X[0]-(X[1]-X[0])]
sec=L[X[0]-(X[1]-X[0]):X[0]-(X[1]-X[0])+(X[1]-X[0])]
#print(first, sec)
if len(first)==0:
    first=sec
if K+1<=len(first):
    print(first[K])
else:
    K=K-len(first)
    print(sec[(K%len(sec))])
