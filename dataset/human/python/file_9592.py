import sys
def S(): return sys.stdin.readline().rstrip()
def I(): return int(sys.stdin.readline().rstrip())
def MI(): return map(int,sys.stdin.readline().rstrip().split())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LS(): return list(sys.stdin.readline().rstrip().split())

n,k = MI()
a = LI()

b = [0]
visited = [0]*n
for _ in range(n):
    if visited[a[b[-1]]-1] == 1:
        break
    visited[a[b[-1]]-1] = 1
    b.append(a[b[-1]]-1)
first = b.index(a[b[-1]]-1)
second = len(b)
if k <= first:
    print(b[k]+1)
else:
    print(b[(k-first)%(second-first)+first]+1)
