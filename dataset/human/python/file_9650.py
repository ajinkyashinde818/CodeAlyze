import sys
sys.setrecursionlimit(100000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

def main():  
    N,K = map(int,input().split())
    A = list(map(int,input().split()))
    A = [a - 1 for a in A]
    X = K.bit_length()
    to = [[-1] * X for _ in range(N)]
    for i,a in enumerate(A):
        to[i][0] = a
    for i in range(X - 1):
        for j in range(N):
            to[j][i + 1] = to[to[j][i]][i]
    now = 0
    i = 0
    while K > 0:
        if K&1:
            now = to[now][i]
        i += 1
        K >>= 1
    print(now + 1)
if __name__ == '__main__':
    main()
