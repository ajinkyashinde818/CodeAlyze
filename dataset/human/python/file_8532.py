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

k,n = inm()
a = inl()
mx = a[0]+k-a[n-1]
for i in range(n-1):
    mx = max(mx, a[i+1]-a[i])
print(k-mx)
