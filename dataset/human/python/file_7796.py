import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():

    N,K,S=map(int,input().split())
    if S>1:
        print(*[S]*(K)+[S-1]*(N-K))
    else:
        print(*[S]*(K)+[S+1]*(N-K))


resolve()
