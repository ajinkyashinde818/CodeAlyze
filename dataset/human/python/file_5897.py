import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    n=int(input())
    la=list(map(int,input().split()))
    lb=list(map(int,input().split()))
    lc=list(map(int,input().split()))
    manzoku=sum(lb)
    for j in range(n-1):
        if la[j+1]-la[j]==1:
            manzoku+=lc[la[j]-1]
    print(manzoku)

resolve()
