import sys

def input():
    return sys.stdin.readline()[:-1]

N, K = map(int, input().split())
A = [i for i in map(int, input().split())]


def func(A, town):
    return A[town]

att = 1

visited = set([1])
loopend = 0
loopstart = 0
if K > N:
    for i in range(N):
        att = func(A, att-1)
        #print(visited)
        if att in visited:
            visited = list(visited)
            loopstart = visited.index(att)
            break
        else:
            visited.add(att)
    loop = visited[loopstart:] # 周回する街
    rem = (K - loopstart) % len(loop)
    att = loop[rem]
else:
    for _ in range(K):
        att = func(A, att-1)

print(att)
