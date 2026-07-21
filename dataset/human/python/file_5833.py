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
a = inl()
b = inl()
c = inl()
sum = 0
for i in range(n):
    sum += b[a[i-1]-1]
    if i<n-1 and a[i+1]==a[i]+1:
        sum += c[a[i]-1]
print(sum)
