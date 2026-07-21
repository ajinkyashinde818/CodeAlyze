def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))
n,m = iim()
cand = []
check = []
for i in range(m):
    a,b = iim()
    if a == 1:
        cand.append(b)
    if b == n:
        check.append(a)

cand = set(cand)
flag=False
for i in check:
    if i in cand:
        flag = True

print('POSSIBLE' if flag else 'IMPOSSIBLE')
