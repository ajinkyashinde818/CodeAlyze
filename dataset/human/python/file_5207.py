import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    N, M = map(int, input().split()) # 頂点の数、辺の数
    edge = [[] for i in range(2)] # rangeに頂点の数。繋がっている頂点を投入するリスト
    for i in range(M): # rangeに辺の数
        a, b = map(int, input().split())
        a, b = a - 1, b - 1
        if a==0 :
            edge[0].append(b)
        elif b==N-1:
            edge[1].append(a)
    if len(set(edge[0])&set(edge[1]))>=1:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')

resolve()
