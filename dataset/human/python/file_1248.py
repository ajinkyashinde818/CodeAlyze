import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]

def main():
    n=int(input())
    aa=LI()
    sum_a=sum(aa)
    s=0
    ans=10**16
    for a in aa[:-1]:
        s+=a
        cur=abs(sum_a-2*s)
        if cur<ans:ans=cur
    print(ans)
main()
