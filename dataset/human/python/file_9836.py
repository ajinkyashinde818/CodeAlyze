import sys 
from collections import deque
sys.setrecursionlimit(10**6)
def S(): return sys.stdin.readline().rstrip()
def SL(): return map(str,sys.stdin.readline().rstrip().split())
def I(): return int(sys.stdin.readline().rstrip())
def IL(): return map(int,sys.stdin.readline().rstrip().split())

def Main():
    n,k = IL()
    a = list(IL())
    chk = [0]*n
    save = []
    current = 0
    for step in range(1,k+1):
        if chk[current]<2:
            if chk[current]==1:
                save.append(current+1)
            chk[current] += 1
            current = a[current]-1
        else:
            break
    else:
        print(current+1)
        exit()
    x = k-step+1
    x %= len(save)
    print(save[x])
    return

if __name__=='__main__':
    Main()
