def inp():
    return input()
def iinp():
    return int(input())
def inps():
    return input().split()
def miinps():
    return map(int,input().split())
def linps():
    return list(input().split())
def lmiinps():
    return list(map(int,input().split()))
def lmiinpsf(n):
    return [list(map(int,input().split()))for _ in range(n)]

k,n = miinps()
a = lmiinps()

l = -1

for i in range(n-1):
  l = max(l,a[i+1]-a[i])

if a[0] == 0:
    l = max(l,k-a[n-1])
else:
    l = max(l,(k-a[n-1])+a[0])

print(k-l)
