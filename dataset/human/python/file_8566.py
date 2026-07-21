import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def main():
    K,N = map(int, readline().split())
    A = [int(i) for i in readline().split()]

    d = 0
    for i in range(N-1):
        tmp = A[i+1] - A[i]
        d = max(d, tmp)

    d = max(d, K - A[-1] + A[0])

    print(K - d)


if __name__ == "__main__":
    main()
