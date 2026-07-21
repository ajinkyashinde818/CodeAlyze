n,m=[int(x) for x in input().split()]
a=[]
b=[]
for i in [0]*n:
    a.append(input())
for i in [0]*m:
    b.append(input())
def check(x,y):
    for i in range(m):
        if a[y+i][x:x+m] != b[i]:
            return False
    return True
from itertools import product
for i,j in product(range(n-m+1),range(n-m+1)):
    if check(i,j):
        print("Yes")
        import sys
        sys.exit()
print("No")
