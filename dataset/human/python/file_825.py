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


n,r = miinps()

if n >= 10:
  print(r)
else:
  print(r + (100*(10-n)))
