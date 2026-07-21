import sys
input = sys.stdin.readline


def main():
    N, M = map(int, input().split())
    A = [list(input()[:-1]) for _ in range(N)]
    B = [list(input()[:-1]) for _ in range(M)]

    for i in range(N-M+1):
        for j in range(N-M+1):
            flg = True
            for y in range(M):
                for x in range(M):
                    if A[i+y][j+x]!=B[y][x]:
                        flg = False
            if flg:
                print('Yes')
                return
    print('No')
    
    

if __name__ == '__main__':
    main()
