import sys
sys.setrecursionlimit(2000000)
s=input()
d='dream'
dr='dreamer'
e='erase'
er='eraser'
l=len(s)
def solve(s,end):
    if end==-1:
        print('YES')
        exit(0)
    if s[end-6:end+1]==dr:
        end-=7
    elif s[end-5:end+1]==er:
        end-=6
    elif s[end-4:end+1]==e or s[end-4:end+1]==d:
        end-=5
    else:
        print('NO')
        exit(0)
    solve(s,end)
solve(s,l-1)
