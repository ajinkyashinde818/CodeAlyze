import sys

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    A = [str(input().strip()) for _ in range(N)]
    B = ''
    for _ in range(M):
        B += str(input().strip())

    for i in range(N-M+1):
        for j in range(N-M+1):
            a = ''
            for k in range(M):
                a += A[i+k][j:j+M]

            if a == B:
                return 'Yes'

    return 'No'


if __name__ == '__main__':
    print(main())
