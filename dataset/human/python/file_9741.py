def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))
import sys 
sys.setrecursionlimit(10000000)


n,k = iim()
A = iil()
d = {0:True}
l = [0]
def move(num):
    l.append(A[num]-1)
    if d.get(A[num]-1,False):
        return True if A[num]-1 == 0 else False
    else:
        d[A[num]-1] = True
        return move(A[num]-1)

if move(0):
    rep = len(l)-1
    ini = 0
else:
    ini = l.index(l[-1])
    rep = len(l)-ini-1

if k <= ini:
    print(l[k]+1)
else:
    mod = (k-ini)%rep
    if mod == 0:
        mod = rep
#    print(l,mod,rep,ini)
    print(l[ini+mod]+1)
