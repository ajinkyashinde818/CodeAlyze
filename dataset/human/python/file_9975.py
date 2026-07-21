import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]

def gcd(a,b):
    while b>0:a,b=b,a%b
    return a

def main():
    a,b=MI()
    print(a*b//gcd(a,b))

main()
