import sys
input = sys.stdin.readline

def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    max_ = A[0] + K - A[-1]
    for i in range(1, N):
        max_ = max(max_, A[i] - A[i-1])
    print(K - max_)

if __name__ == "__main__":
    main()
