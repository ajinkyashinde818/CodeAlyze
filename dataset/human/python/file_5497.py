import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    L=[0,1,2,3,4,5,6,7,8,9,'A', 'B', 'C','D','E','F']

    x,y=map(str,input().split())
    if L.index(x)==L.index(y):
        print('=')
    elif L.index(x)>L.index(y):
        print('>')
    else:
        print('<')

    
resolve()
