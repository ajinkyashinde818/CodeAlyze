from bisect import bisect_right
import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def pf(x):
    ee=[]
    pp=[]
    if x&1==0:
        k=(x&-x).bit_length()-1
        pp.append(2)
        ee.append(k)
        x>>=k
    d=3
    while d**2<=x:
        while x%d==0:
            x//=d
            if pp and pp[-1]==d:ee[-1]+=1
            else:
                pp.append(d)
                ee.append(1)
        d+=2

    if x>1:
        if pp and pp[-1] == x: ee[-1] += 1
        else:ee.append(1)

    return ee

def main():
    n=II()
    ss=[1]
    for a in range(2,45):ss.append(ss[-1]+a)
    #print(ss)
    ee=pf(n)
    #print(ee)
    ans=0
    for e in ee:
        i=bisect_right(ss,e)
        ans+=i
    print(ans)

main()
