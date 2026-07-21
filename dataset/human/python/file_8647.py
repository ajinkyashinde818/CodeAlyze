import math
def py():
    print("Yes")
def pn():
    print("No")
def iin():
    x = int(input())
    return x

neko = 0
nya = 0
nuko = 0
k,n = map(int,input().split())
a = [int(x) for x in input().split()]
a.sort()
a.append(a[0]+k)
for i in range(n):
    if neko < a[i+1] - a[i]:
        neko = a[i+1] - a[i]
print(k-neko)
