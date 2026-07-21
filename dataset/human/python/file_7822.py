from sys import stdout
printn = lambda x: stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True # and False
BIG = 999999999
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

n,k,s = inm()
r = 10**9
if s==10**9:
    r = 1
for i in range(k):
    printn(str(s)+' ')
for i in range(n-k):
    printn(str(r)+' ')
print('')
