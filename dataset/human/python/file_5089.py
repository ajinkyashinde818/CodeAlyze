import numpy as np

n, m = [int(i) for i in input().split()]

connected_1 = {}

for i in range(m):
    a, b = [int(i) for i in input().split()]
    
    if a == 1:
        if connected_1.get(b) is None:
            connected_1[b] = 1
        elif connected_1[b] ==1:
            print("POSSIBLE")
            break
        
        
    if b == n:
        if connected_1.get(a) is None:
            connected_1[a] = 1
        elif connected_1[a] ==1:
            print("POSSIBLE")
            break
        
       
        
    if i==m-1:
        print("IMPOSSIBLE")
