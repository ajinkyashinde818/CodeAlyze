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

n = inn()
if n%2 == 1:
    print(0)
    exit()
m = n//2
x = 0
for i in range(1,30):
    x += m//(5**i)
print(x)
