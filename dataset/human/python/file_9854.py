import sys, os

def f():
    args = list(map(int,input().split()))
    if len(args) > 1:
        return args
    return args[0]

if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n,k  = f()
    A = f()

    A = [0] + A
    last = [-1] * (n+1)

    last[1] = 0
    cur= 1

    pos = -1
    cycle = -1

    if k < n:
        for i in range(k):
            cur = A[cur]
        print(cur)
    else:
        for i in range(n):
            nxt = A[cur]
            if  i == n-1:
                pos = nxt
                cycle = n-1 - last[nxt]
            last[nxt] = i
            cur = nxt
            

        steps = (k - n)%cycle
        cur = pos
        for i in range(steps):
            cur = A[cur]
        print(cur)

solve()
