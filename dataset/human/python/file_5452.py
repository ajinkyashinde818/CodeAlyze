import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n = input()
    if '9' in n:
        print('Yes')
    else:
        print('No')

solve()
