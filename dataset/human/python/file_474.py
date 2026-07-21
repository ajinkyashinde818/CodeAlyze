import sys
input = sys.stdin.readline

def read():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    return N, A


def solve(N, A):
    abs_a = list(map(abs, A))
    min_a = min(abs_a)
    for i in range(N-1):
        if A[i] < 0:
            A[i] = -A[i]
            A[i+1] = -A[i+1]
    if A[N-1] < 0:
        return sum(abs_a) - min_a * 2
    else:
        return sum(abs_a)


if __name__ == '__main__':
    inputs = read()
    print(solve(*inputs))
