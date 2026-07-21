import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]

def main():
    n,m=MI()
    start=set()
    goal=set()
    for _ in range(m):
        a,b=MI()
        if a>b:a,b=b,a
        if a==1:start.add(b)
        if b==n:goal.add(a)
    if start&goal:print("POSSIBLE")
    else:print("IMPOSSIBLE")
main()
