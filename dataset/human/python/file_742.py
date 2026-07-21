xs,ys,xt,yt=map(int,input().split())
N=int(input())
import numpy as np
XYR=np.empty((N+2,3),dtype=np.float64)
XYR[1:-1,:]=np.array([input().split() for i in range(N)])
XYR[0,:]=xs,ys,0
XYR[-1,:]=xt,yt,0
X,Y,R=XYR.T
c=np.maximum(0,np.sqrt(np.square(X[None,:]-X[:,None])+np.square(Y[None,:]-Y[:,None]))-R[None,:]-R[:,None])
c[range(N+2),range(N+2)]=-1
from scipy.sparse import*
g=csgraph.csgraph_from_dense(c,null_value=-1)
print(csgraph.dijkstra(g,indices=0)[-1])
