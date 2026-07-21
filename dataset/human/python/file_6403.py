import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    
    n=int(input())
    
    if n%2==1:
        print(0)
    else:
        N=n//2
        cnt=0
        while N>=5:
            cnt+=N//5
            N//=5
        print(int(cnt))
        



    
resolve()
