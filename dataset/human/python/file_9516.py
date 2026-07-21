import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI1(): return list(map(int1, sys.stdin.readline().split()))
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    n,k=MI()
    aa=LI1()
    pos=[-1]*n
    i=aa[0]
    pos[0]=0
    log=[0]
    j=1
    while pos[i]==-1:
        log.append(i)
        if j==k:
            print(log[-1]+1)
            exit()
        pos[i]=j
        i=aa[i]
        j+=1
    pre=pos[i]
    k-=pre
    t=len(log)-pre
    k%=t
    print(log[pre+k]+1)

main()
