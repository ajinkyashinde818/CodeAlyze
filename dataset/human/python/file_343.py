import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def ii(): return int(input())
def mi(): return map(int, input().split())
def lmi(): return list(map(int, input().split()))
def lmif(n): return [list(map(int, input().split())) for _ in range(n)]
def ss(): return input().split()

def main():
    mod = 1000000007
    
    N = ii()
    A = lmi()

    mz_count = 0 # minus or zero
    mz_min = 10 ** 10
    ans = 0
    for i in A:
        if i <= 0:
            mz_count += 1
            i = -i
        ans += i
        if mz_min > i:
            mz_min = i
    
    if mz_count % 2 == 0:
        print(ans)
    else:
        print(ans - 2 * mz_min)    

    return

main()
