import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    N, M = map(int, readline().split())
    A = []
    B = []
    for _ in range(N):
        A.append(readline().decode('utf-8').strip())
    for _ in range(M):
        B.append(readline().decode('utf-8').strip())
    AH = N
    AW = len(A[0])
    BH = M
    BW = len(B[0])
    ans = 'No'
    for i in range(AH-BH+1):
        for j in range(AW-BW+1):
            if A[i][j:j+BW] == B[0]:
                for h in range(BH):
                    if A[i+h][j:j+BW] == B[h]:
                        continue
                    else:
                        break
                else:
                    ans = 'Yes'
    print(ans)

if __name__ == '__main__':
    main()
