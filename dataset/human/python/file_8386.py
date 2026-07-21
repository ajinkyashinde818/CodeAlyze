import sys
input = sys.stdin.readline


def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    diff = [A[i+1] - A[i] for i in range(N-1)]
    diff.append(A[0]+K-A[N-1])
    print(sum(diff)-max(diff))


if __name__ == '__main__':
    main()
