import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n  = f()[0]
    a = f()

    s = [0] * n
    for i in range(n):
        s[i] = a[i] + (s[i-1] if i>0 else 0)

    mina = abs(s[n-1]-2*s[0])

    for i in range(n-1):
        mina = min(mina, abs(s[n-1] - 2*s[i]))
    
    print(mina)

solve()
