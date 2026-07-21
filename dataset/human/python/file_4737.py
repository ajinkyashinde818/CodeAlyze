import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

s = list(input())
t = list(input())
s.sort()
t.sort(reverse=True)

lens = len(s)
lent = len(t)
for i in range(lens):
    if i==lent:
        print('No')
        exit()
    if s[i]<t[i]:
        print('Yes')
        exit()
    elif s[i]>t[i]:
        print('No')
        exit()
else:
    if len(t)==len(s):
        print('No')
    else:
        print('Yes')
