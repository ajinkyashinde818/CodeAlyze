import sys

input = sys.stdin.readline


def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    a = sum([B[i - 1] for i in A])
    c = sum([C[i - 1] for i, j in zip(A[:-1], A[1:]) if i == j - 1])
    print(a + c)


if __name__ == "__main__":
    main()
