import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


s = list(S())
t = list(S())
# s' はなるべく辞書順で前に来るように， t' はなるべくあとに来るように並び替えて比べる
ns = ''.join(sorted(s))
nt = ''.join(sorted(t)[::-1])
if ns < nt:
    print('Yes')
else:
    print('No')
