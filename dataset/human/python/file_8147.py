import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    k,s = f()
    
    cnt = 0
    for i in range(k+1):
        for j in range(k+1):
            if s-i -j >=0 and s-i -j<= k:
                cnt += 1

    
    print(cnt)


solve()
