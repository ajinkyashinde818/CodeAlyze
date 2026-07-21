import sys
import math

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]

def main():
    n=int(input())
    if n%2:
        print(0)
        exit()
    ans=0
    d=10
    for _ in range(26):
        ans+=n//d
        d*=5
    print(ans)

main()
