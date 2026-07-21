import numpy as np
import sys
n,m=map(int,input().split())
a= [list(input()) for i in range(n)] 
b= [list(input()) for i in range(m)] 
na=np.array(a)

sa=n-m+1

for x in range(sa):
    for y in range(sa):

        if na[x:x+m,y:y+m].tolist()==b:
            print("Yes")
            sys.exit()
print("No")
