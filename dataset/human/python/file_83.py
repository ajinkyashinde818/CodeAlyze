import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    R,G,B,N=map(int,input().split())
    cnt=0
    for r in range(N+1):
        for g in range(N+1):
            val=(N-R*r-G*g)/B
            if val==int(val) and val>=0:
                cnt+=1
    print(cnt)

resolve()
