import numpy as np
a,b = [int(i) for i in input().split()]

al = np.array([list(input()) for _ in range(a)])
bl = np.array([list(input()) for _ in range(b)])

flg  = False
for i in range(a - b + 1):
    for j in range(a - b + 1):
        if(al[i:i+b,j:j+b] == bl).all():
            flg = True
            
print('Yes' if flg else 'No')
