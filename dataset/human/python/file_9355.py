import sys
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9 + 7
input = sys.stdin.readline

def inp():
    return int(input())
def inpl():
    return list(map(int,input().split()))
def inpm():
    return map(int,input().split())

n,k =map(int,input().split())

a=[1] + inpl()
b=[-1] * (n+1); b[1] = 0
place = 1
turn = 0

while b[a[place]] == -1:
    place = a[place]
    turn += 1
    b[place] = turn
r = (k - turn) % (b[place] - b[a[place]] + 1)

if k < turn:
    print(b.index(k))
else:
    for _ in range(r):
        place = a[place]
    print(place)
