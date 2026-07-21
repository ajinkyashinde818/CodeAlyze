from sys import stdout
printn = lambda x: stdout.write(str(x))
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 999999999
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

n = ins()
nrev = n[::-1]
m = len(n)
l = [0]*(m+1)
r = [0]*(m+1)
r[m] = 1
for k in range(m,0,-1):
    p = int(nrev[k-1])
    l[k-1] = min(l[k]+p, r[k]+10-p)
    if k>0:
        r[k-1] = min(l[k]+p+1, r[k]+10-p-1)
print(l[0])
