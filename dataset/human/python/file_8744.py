import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    print(K - max([A[i+1] - A[i] for i in range(N-1)] + [K-A[N-1]+A[0]]))

if __name__ == '__main__':
    main()
