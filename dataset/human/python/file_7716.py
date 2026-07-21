import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    x = f()[0]
    if x >= 1200:
        print("ARC")
    else:
        print("ABC")

solve()
