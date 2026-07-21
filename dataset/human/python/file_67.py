import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    R,G,B,N=map(int, input().split())
    cnt=0
    rnum=N//R
    gnum=N//G
    for r in range(rnum+1):
        for g in range(gnum+1):
            x=R*r+G*g
            if x>N:
                break
            else:
                if (N-x)%B==0:
                    cnt+=1
    print(cnt)
resolve()
