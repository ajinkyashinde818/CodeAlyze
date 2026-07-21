import sys


def input():
    return sys.stdin.readline()[:-1]


def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]

    ans = sum(B)
    for i in range(N-1):
        if A[i]+1 == A[i+1]:
            ans += C[A[i]-1]
    print(ans)


if __name__ == '__main__':
    main()
