import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n,m = f()
    a = [""] * n
    b = [""] * m
    for i in range(n):
        a[i] = input()
    
    for i in range(m):
        b[i] = input()
    
    if m>n:
        print("No")
    else:
        for i in range(0, n - m+1):
            for j in range(0, n - m+1):
                ok = True
                for k in range(m):
                    if a[i+k][j:j+ m] != b[k]:
                        ok = False
                if ok:
                    print("Yes")
                    return
        
        print("No")


solve()
