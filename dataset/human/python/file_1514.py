printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

n,m = inm()
a = []
b = []
for i in range(n):
    a.append(ins())
for i in range(m):
    b.append(ins())
for i in range(n-m+1):
    for j in range(n-m+1):
        ok = True
        for k in range(m):
            if a[i+k][j:j+m]!=b[k]:
                ok = False
                break
        if ok:
            print('Yes')
            exit()
print('No')
