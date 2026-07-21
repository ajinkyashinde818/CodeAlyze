import sys

input = sys.stdin.readline


def solve(A, B, C):
    prev_a = -1
    result = 0
    for a in A:
        result += B[a - 1]
        if a - prev_a == 1:
            result += C[prev_a - 1]
        prev_a = a

    return result


if __name__ == '__main__':
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    answer = solve(A, B, C)
    print(answer)
