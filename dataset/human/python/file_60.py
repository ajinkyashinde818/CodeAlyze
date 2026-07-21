import numpy as np

r,g,b,n=map(int,input().split())

x = np.arange(3001)
t = np.array([np.arange(0,3001*g,g)]*3001).T
y = np.array([x]*3001)
z = y*r+t
print(np.sum(np.logical_and((n-z)%b==0,n-z>=0)))
