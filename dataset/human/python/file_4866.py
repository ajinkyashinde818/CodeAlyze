import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    s = input()
    t = input()

    s = sorted(s)
    t = sorted(t)

    for i in s:
        for j in t:
            if ord(i)< ord(j):
                print('Yes')
                return


    if len(s)<len(t):
        ok = 1
        for i in s:
            if i not in t:
                ok = 0
        if ok:
            print('Yes')
            return


    print('No')

solve()
