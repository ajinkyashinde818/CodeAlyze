import sys
n, m = [int(i) for i in sys.stdin.readline().split()]
graph = [[0 for i in range(n)] for j in range(2)]
for i in range(m):
    a, b = [int(i) for i in sys.stdin.readline().split()]
    a -= 1
    b -= 1
    if a == 0:
        graph[a][b] = 1
    if b == n - 1:
        graph[1][a] = 1
flg = False
for i in range(n):
    if graph[0][i] & graph[1][i]:
        flg = True
if flg:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
