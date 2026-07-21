import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    s = input()
    s = set(s)


    if 'a' in s and 'b' in s and 'c' in s:
        print('Yes')
    else:
        print('No')
    

solve()
