import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    r,g,b,n = f()
    ans = 0
    for i in range(n//r + 1):
        for j in range((n-r*i)//g +1 ):
            if (n-r*i - g*j)%b == 0:
                ans += 1

    
    print(ans)

solve()
