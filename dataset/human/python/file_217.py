import math

def mk(n):
    if (n == 1):
        return [[1], [1]]
    else:
        y = (n*(n-1)) // 2 + 1
        p = mk(n-1)
        for i in range(0,n):
            p[i].append(y+i)
        p.append([a+y for a in range(n)])
        return p


m = int(input())
x = math.floor(math.sqrt(2*m))
if (not x*(x+1) == 2*m):
    print("No")
else:
    print("Yes")
    print(x+1)
    p = mk(x)
    for i in range(x + 1):
        print(x," ", end="")
        for e in p[i]:
            print(e," ", end="")
        print()
