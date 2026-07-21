import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    k,n=MI()
    aa=LI()
    mx=k-aa[-1]+aa[0]
    for a0,a1 in zip(aa,aa[1:]):
        mx=max(mx,a1-a0)
    print(k-mx)

main()
